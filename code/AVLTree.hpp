

#include"Tree.hpp"
#include<stack>
#include<queue>
template<typename Q>
class AVLTree:public Tree<Q>
{


public:
	//右旋转
	void R_Rotate(BiTNode2<Q>** P);
	//左旋转
	void L_Rotate(BiTNode2<Q>** P);
	//左平衡
	void LeftBalance(BiTNode2<Q>** T);
	//右平衡
	void RightBalance(BiTNode2<Q>** T);
	//删除结点
	void Delete_Node(BiTNode2<Q>* T);
public:

	//查找
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p);
	//插入
	virtual Status Insert(BiTNode2<Q>** Root, Q key);
	//删除
	virtual Status Delete(BiTNode2<Q>** Root, Q key);
	//先序遍历
	virtual Status PreOrder(BiTNode2<Q>* T);
	//中序遍历
	virtual Status InOrder(BiTNode2<Q>* T);
	//后序遍历
	virtual Status PostOrder(BiTNode2<Q>* T);
	//层次遍历
	virtual Status LevelOrder(BiTNode2<Q>* T);
	//先序遍历（非递归）
	virtual Status PreOrder2(BiTNode2<Q>* T);
	//中序遍历（非递归）
	virtual Status InOrder2(BiTNode2<Q>* T);
	//后序遍历（非递归）
	virtual Status PostOrder2(BiTNode2<Q>* T);



};

// 对以p为根的二叉排序树作右旋处理， 
// 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点 
template<typename Q>
void AVLTree<Q>::R_Rotate(BiTNode2<Q>** P)
{
	BiTNode2<Q>* L;
	L = (*P)->lchild; //  L指向P的左子树根结点
	(*P)->lchild = L->rchild; //  L的右子树挂接为P的左子树 
	L->rchild = (*P);
	*P = L; //  P指向新的根结点 
}

// 对以P为根的二叉排序树作左旋处理， 
// 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点0  
template<typename Q>
void AVLTree<Q>::L_Rotate(BiTNode2<Q>** P)
{
	BiTNode2<Q>* R;
	R = (*P)->rchild; /*  R指向P的右子树根结点 */
	(*P)->rchild = R->lchild; /* R的左子树挂接为P的右子树 */
	R->lchild = (*P);
	*P = R; /*  P指向新的根结点 */
}



//  对以指针T所指结点为根的二叉树作左平衡旋转处理
template<typename Q>
void AVLTree<Q>::LeftBalance(BiTNode2<Q>** T)
{
	BiTNode2<Q>* L, *Lr;
	L = (*T)->lchild; /*  L指向T的左子树根结点 */
	switch (L->bf)
	{
	case LH: /*  新结点插入在T的左孩子的左子树上，要作单右旋处理 */
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH: /*  新结点插入在T的左孩子的右子树上，要作双旋处理 */
		Lr = L->rchild;
		switch (Lr->bf)
		{ /*  修改T及其左孩子的平衡因子 */
		case LH: (*T)->bf = RH;
			L->bf = EH;
			break;
		case EH: (*T)->bf = L->bf = EH;
			break;
		case RH: (*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild); 
		R_Rotate(T); 
	}
}

//  对以指针T所指结点为根的二叉树作右平衡旋转处理， 
template<typename Q>
void AVLTree<Q>::RightBalance(BiTNode2<Q>** T)
{
	BiTNode2<Q>* R,* Rl;
	R = (*T)->rchild; /*  R指向T的右子树根结点 */
	switch (R->bf)
	{
	case RH: /*  新结点插入在T的右孩子的右子树上，要作单左旋处理 */
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH: 
		Rl = R->lchild; 			
		switch (Rl->bf)
		{ 						/*  修改T及其右孩子的平衡因子 */
		case RH: (*T)->bf = LH;
			R->bf = EH;
			break;
		case EH: (*T)->bf = R->bf = EH;
			break;
		case LH: (*T)->bf = EH;
			R->bf = RH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild); 
		L_Rotate(T);
	}
}

//  若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个 
//  数据元素为e的新结点，并返回1，否则返回0。若因插入而使二叉排序树 
//  失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否。 
template<typename Q>
Status AVLTree<Q>::Insert(BiTNode2<Q>** Root, Q e)
{
	bool taller=FALSE;
	if (!*Root)
	{ 
		*Root = new BiTNode2<Q>;
		(*Root)->data = e; (*Root)->lchild = (*Root)->rchild = nullptr; (*Root)->bf = EH;
		taller = TRUE;
	}
	else
	{
		if (e == (*Root)->data)
		{
			taller = FALSE; return FALSE; // 树中已存在和e有相同关键字的结点则不再插入 
		}
		if (e < (*Root)->data)
		{ 
			if (!Insert(&(*Root)->lchild, e)) /*  未插入 */
				return FALSE;
			if (taller) /*   已插入到T的左子树中且左子树“长高” */
				switch ((*Root)->bf) 
				{
				case LH: /*  原本左子树比右子树高，需要作左平衡处理 */
					LeftBalance(Root);	taller = FALSE; break;
				case EH: /*  原本左、右子树等高，现因左子树增高而使树增高 */
					(*Root)->bf = LH; taller = TRUE; break;
				case RH: /*  原本右子树比左子树高，现左、右子树等高 */
					(*Root)->bf = EH; taller = FALSE; break;
				}
		}
		else
		{
			if (!Insert(&(*Root)->rchild, e)) /*  未插入 */
				return FALSE;
			if (taller) /*  已插入到T的右子树且右子树“长高” */
				switch ((*Root)->bf) 
				{
				case LH: /*  原本左子树比右子树高，现左、右子树等高 */
					(*Root)->bf = EH; taller = FALSE;	break;
				case EH: /*  原本左、右子树等高，现因右子树增高而使树增高  */
					(*Root)->bf = RH; taller = TRUE; break;
				case RH: /*  原本右子树比左子树高，需要作右平衡处理 */
					RightBalance(Root); taller = FALSE; break;
				}
		}
	}
	return TRUE;
}

//template<typename Q>
//S

//*/
template<typename Q>
void AVLTree<Q>::Delete_Node(BiTNode2<Q>* T)
{
	BiTNode2<Q>* Q1,* Q2;
	if (!T->lchild)
	{	//如果左子树为空，则只需重接其右子树
		Q1 = T;
		T = T->rchild;
		delete Q1;
	}
	else if (!T->rchild)
	{	//如果右子树为空，则只需重接其左子树
		Q1 = T;
		T = T->lchild;
		delete Q1;
	}
	else
	{	
		//我们这里采取修改左子树的方法，也可以修改右子树
		Q1 = T;
		Q2 = T->lchild;		//取待删节点的左节点
		while (Q2->rchild)
		{	//一直向右，最终Q2为待删节点的前驱节点。
			Q1 = Q2;
			Q2 = Q2->rchild;
		}
		//用Q2来替换待删节点Q1
		T->data = Q2->data;
		//根据情况，将s的左子树重接到q上
		if (T != Q1)
			Q1->rchild = Q2->lchild;
		else
			Q1->lchild = Q2->lchild;
		delete Q2;
	}
}
template<typename Q>
Status AVLTree<Q>::Delete(BiTNode2<Q>** Root, Q key)
{
	//不存在关键字为key的节点
	if (!*Root)
		return FALSE;
	else
	{
		if (key == (* Root)->data)       //查找到关键字为key的节点
		{
			Delete_Node(*Root);
			return TRUE;
		}
		else if (key < (*Root)->data)  //继续查找左子树
			return Delete(&(*Root)->lchild, key);
		else                        //继续查找右子树
			return Delete(&(*Root)->rchild, key);
	}
}

template<typename Q>
Status AVLTree<Q>::Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p)
{
	if (T == nullptr)	/*  查找不成功 */
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data) /*  查找成功 */
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return Search(T->lchild, key, T, p);  /*  在左子树中继续查找 */
	else
		return Search(T->rchild, key, T, p);  /*  在右子树中继续查找 */
}
template<typename Q>
Status AVLTree<Q>::PreOrder(BiTNode2<Q>* T)
{
	int flag=0;
	if (T == nullptr&&flag==0)
	{
		return FALSE;
	}
	else
	{
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		flag = 1;
		return TRUE;
	}
		
}

//中序遍历
template<typename Q>
Status AVLTree<Q>::InOrder(BiTNode2<Q>* T)
{
	int flag = 0;
	if (T == nullptr && flag == 0)
	{
		return FALSE;
		
	}
	else
	{
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
		flag = 1;
		return TRUE;
	}
		
}


//后序遍历
template<typename Q>
Status AVLTree<Q>::PostOrder(BiTNode2<Q>* T)
{
	int flag = 0;
	if (T == nullptr&&flag==0)
	{
		return FALSE;
	}
	else
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
		flag = 1;
		return TRUE;
	}
		
}


//层次遍历
template<typename Q>
Status AVLTree<Q>::LevelOrder(BiTNode2<Q>* Root)
{
	if (Root == nullptr)
	{
		return FALSE;
	}

	BiTNode2<Q>* tree = Root;

	//队列  
	queue<BiTNode2<Q>*> q1;

	//根节点入队  
	q1.push(tree);

	//队列不空循环  
	while (!q1.empty())
	{

		//输出队头元素 
		tree = q1.front();

		//访问队头指向的结点数据
		cout << tree->data << " ";

		//队头出队
		q1.pop();

		//左子树不为空，将左子树入队  
		if (tree->lchild != nullptr)
		{
			q1.push(tree->lchild);
		}

		//右子树不空，将右子树入队  
		if (tree->rchild != nullptr)
		{
			q1.push(tree->rchild);
		}
	}
	return TRUE;
}



template<typename Q>
Status AVLTree<Q>::PreOrder2(BiTNode2<Q>* Root)//前序遍历的非递归实现
{
	stack<BiTNode2<Q>*> s1;
	if (Root != nullptr)
	{
		s1.push(Root);//先将二叉树的根节点push进栈。  
	}
	else
		return FALSE;
	while (!s1.empty())//栈不为空的条件下，执行一个循环
	{
		BiTNode2<Q>* top = s1.top();//先对top->rchild进行判断是否入栈，再对top->lchild进行判断是否入栈
		s1.pop();
		cout << top->data << " ";
		if (top->rchild != nullptr)
			s1.push(top->rchild);
		if (top->lchild != nullptr)
			s1.push(top->lchild);
	}
	return TRUE;
}


template<typename Q>
Status AVLTree<Q>::InOrder2(BiTNode2<Q>* Root)//中序遍历的非递归实现
{
	if (Root == nullptr)
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s2;
	while (Root != nullptr || !s2.empty())//从当前节点Root开始，以Root为循环条件，当Root不为空时，将Root入栈，然后以Root->lchiled跟进					    
	{
		while (Root != nullptr)
		{
			s2.push(Root);
			Root = Root->lchild;
		}
		BiTNode2<Q>* top = s2.top();//取栈顶节点：先保存该节点
		cout << top->data << " ";
		s2.pop();
		Root = top->rchild;
	}
	return TRUE;
}



//非递归后序遍历（左节点->右节点->根节点）思想：即用栈实现  
//（1）在当前节点cur不为空或栈不为空的条件下（在该条件下的原因：该条件说明未遍历完二叉树）。  
//（2）从当前节点cur开始，以cur为循环条件，当cur不为空时，将cur入栈，然后以cur=cur->_left跟进，直至  
//     将该二叉树的最左节点入栈后，入栈操作结束。取栈顶节点top：先保存该节点（用top保存该节点的原因：  
//     还要考虑该节点的右孩子），  
//（3）若top->_right==NULL || lastVisited == top->_right,则输出top->_value,执行栈的pop操作,并执行lastVisited = top(  
//    用lastVisited保存最近一个所输出的节点，待到下一次同样的操作时，若lastVisited == top->_right，则  
//    说明top的右节点已经访问过了，可以访问top了，否则会陷在cur = top->_right这步操作里）;  
//（4）若条件（3）不满足，则继续以top->_right为cur值，转（1）操作.  
template<typename Q>
Status AVLTree<Q>::PostOrder2(BiTNode2<Q>* Root)//后序遍历的非递归实现
{
	if (Root == nullptr)
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s3;
	BiTNode2<Q>* lastVisited = nullptr;
	while (Root != nullptr || !s3.empty())
	{
		while (Root != nullptr)
		{
			s3.push(Root);
			Root = Root->lchild;
		}
		BiTNode2<Q>* top = s3.top();
		if (top->rchild == nullptr || lastVisited == top->rchild)
		{
			s3.pop();
			cout << top->data << " ";
			lastVisited = top;
		}
		else
			Root = top->rchild;
	}
	return TRUE;
}
