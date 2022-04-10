

#include"Tree.hpp"
#include<stack>
#include<queue>
template<typename Q>
class AVLTree:public Tree<Q>
{


public:
	//����ת
	void R_Rotate(BiTNode2<Q>** P);
	//����ת
	void L_Rotate(BiTNode2<Q>** P);
	//��ƽ��
	void LeftBalance(BiTNode2<Q>** T);
	//��ƽ��
	void RightBalance(BiTNode2<Q>** T);
	//ɾ�����
	void Delete_Node(BiTNode2<Q>* T);
public:

	//����
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p);
	//����
	virtual Status Insert(BiTNode2<Q>** Root, Q key);
	//ɾ��
	virtual Status Delete(BiTNode2<Q>** Root, Q key);
	//�������
	virtual Status PreOrder(BiTNode2<Q>* T);
	//�������
	virtual Status InOrder(BiTNode2<Q>* T);
	//�������
	virtual Status PostOrder(BiTNode2<Q>* T);
	//��α���
	virtual Status LevelOrder(BiTNode2<Q>* T);
	//����������ǵݹ飩
	virtual Status PreOrder2(BiTNode2<Q>* T);
	//����������ǵݹ飩
	virtual Status InOrder2(BiTNode2<Q>* T);
	//����������ǵݹ飩
	virtual Status PostOrder2(BiTNode2<Q>* T);



};

// ����pΪ���Ķ������������������� 
// ����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ���� 
template<typename Q>
void AVLTree<Q>::R_Rotate(BiTNode2<Q>** P)
{
	BiTNode2<Q>* L;
	L = (*P)->lchild; //  Lָ��P�������������
	(*P)->lchild = L->rchild; //  L���������ҽ�ΪP�������� 
	L->rchild = (*P);
	*P = L; //  Pָ���µĸ���� 
}

// ����PΪ���Ķ������������������� 
// ����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ����0  
template<typename Q>
void AVLTree<Q>::L_Rotate(BiTNode2<Q>** P)
{
	BiTNode2<Q>* R;
	R = (*P)->rchild; /*  Rָ��P������������� */
	(*P)->rchild = R->lchild; /* R���������ҽ�ΪP�������� */
	R->lchild = (*P);
	*P = R; /*  Pָ���µĸ���� */
}



//  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
template<typename Q>
void AVLTree<Q>::LeftBalance(BiTNode2<Q>** T)
{
	BiTNode2<Q>* L, *Lr;
	L = (*T)->lchild; /*  Lָ��T������������� */
	switch (L->bf)
	{
	case LH: /*  �½�������T�����ӵ��������ϣ�Ҫ������������ */
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH: /*  �½�������T�����ӵ��������ϣ�Ҫ��˫������ */
		Lr = L->rchild;
		switch (Lr->bf)
		{ /*  �޸�T�������ӵ�ƽ������ */
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

//  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� 
template<typename Q>
void AVLTree<Q>::RightBalance(BiTNode2<Q>** T)
{
	BiTNode2<Q>* R,* Rl;
	R = (*T)->rchild; /*  Rָ��T������������� */
	switch (R->bf)
	{
	case RH: /*  �½�������T���Һ��ӵ��������ϣ�Ҫ������������ */
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH: 
		Rl = R->lchild; 			
		switch (Rl->bf)
		{ 						/*  �޸�T�����Һ��ӵ�ƽ������ */
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

//  ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ�� 
//  ����Ԫ��Ϊe���½�㣬������1�����򷵻�0����������ʹ���������� 
//  ʧȥƽ�⣬����ƽ����ת������������taller��ӳT������� 
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
			taller = FALSE; return FALSE; // �����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ��� 
		}
		if (e < (*Root)->data)
		{ 
			if (!Insert(&(*Root)->lchild, e)) /*  δ���� */
				return FALSE;
			if (taller) /*   �Ѳ��뵽T�����������������������ߡ� */
				switch ((*Root)->bf) 
				{
				case LH: /*  ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */
					LeftBalance(Root);	taller = FALSE; break;
				case EH: /*  ԭ�����������ȸߣ��������������߶�ʹ������ */
					(*Root)->bf = LH; taller = TRUE; break;
				case RH: /*  ԭ�����������������ߣ������������ȸ� */
					(*Root)->bf = EH; taller = FALSE; break;
				}
		}
		else
		{
			if (!Insert(&(*Root)->rchild, e)) /*  δ���� */
				return FALSE;
			if (taller) /*  �Ѳ��뵽T���������������������ߡ� */
				switch ((*Root)->bf) 
				{
				case LH: /*  ԭ�����������������ߣ������������ȸ� */
					(*Root)->bf = EH; taller = FALSE;	break;
				case EH: /*  ԭ�����������ȸߣ��������������߶�ʹ������  */
					(*Root)->bf = RH; taller = TRUE; break;
				case RH: /*  ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */
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
	{	//���������Ϊ�գ���ֻ���ؽ���������
		Q1 = T;
		T = T->rchild;
		delete Q1;
	}
	else if (!T->rchild)
	{	//���������Ϊ�գ���ֻ���ؽ���������
		Q1 = T;
		T = T->lchild;
		delete Q1;
	}
	else
	{	
		//���������ȡ�޸��������ķ�����Ҳ�����޸�������
		Q1 = T;
		Q2 = T->lchild;		//ȡ��ɾ�ڵ����ڵ�
		while (Q2->rchild)
		{	//һֱ���ң�����Q2Ϊ��ɾ�ڵ��ǰ���ڵ㡣
			Q1 = Q2;
			Q2 = Q2->rchild;
		}
		//��Q2���滻��ɾ�ڵ�Q1
		T->data = Q2->data;
		//�����������s���������ؽӵ�q��
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
	//�����ڹؼ���Ϊkey�Ľڵ�
	if (!*Root)
		return FALSE;
	else
	{
		if (key == (* Root)->data)       //���ҵ��ؼ���Ϊkey�Ľڵ�
		{
			Delete_Node(*Root);
			return TRUE;
		}
		else if (key < (*Root)->data)  //��������������
			return Delete(&(*Root)->lchild, key);
		else                        //��������������
			return Delete(&(*Root)->rchild, key);
	}
}

template<typename Q>
Status AVLTree<Q>::Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p)
{
	if (T == nullptr)	/*  ���Ҳ��ɹ� */
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data) /*  ���ҳɹ� */
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return Search(T->lchild, key, T, p);  /*  ���������м������� */
	else
		return Search(T->rchild, key, T, p);  /*  ���������м������� */
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

//�������
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


//�������
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


//��α���
template<typename Q>
Status AVLTree<Q>::LevelOrder(BiTNode2<Q>* Root)
{
	if (Root == nullptr)
	{
		return FALSE;
	}

	BiTNode2<Q>* tree = Root;

	//����  
	queue<BiTNode2<Q>*> q1;

	//���ڵ����  
	q1.push(tree);

	//���в���ѭ��  
	while (!q1.empty())
	{

		//�����ͷԪ�� 
		tree = q1.front();

		//���ʶ�ͷָ��Ľ������
		cout << tree->data << " ";

		//��ͷ����
		q1.pop();

		//��������Ϊ�գ������������  
		if (tree->lchild != nullptr)
		{
			q1.push(tree->lchild);
		}

		//���������գ������������  
		if (tree->rchild != nullptr)
		{
			q1.push(tree->rchild);
		}
	}
	return TRUE;
}



template<typename Q>
Status AVLTree<Q>::PreOrder2(BiTNode2<Q>* Root)//ǰ������ķǵݹ�ʵ��
{
	stack<BiTNode2<Q>*> s1;
	if (Root != nullptr)
	{
		s1.push(Root);//�Ƚ��������ĸ��ڵ�push��ջ��  
	}
	else
		return FALSE;
	while (!s1.empty())//ջ��Ϊ�յ������£�ִ��һ��ѭ��
	{
		BiTNode2<Q>* top = s1.top();//�ȶ�top->rchild�����ж��Ƿ���ջ���ٶ�top->lchild�����ж��Ƿ���ջ
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
Status AVLTree<Q>::InOrder2(BiTNode2<Q>* Root)//��������ķǵݹ�ʵ��
{
	if (Root == nullptr)
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s2;
	while (Root != nullptr || !s2.empty())//�ӵ�ǰ�ڵ�Root��ʼ����RootΪѭ����������Root��Ϊ��ʱ����Root��ջ��Ȼ����Root->lchiled����					    
	{
		while (Root != nullptr)
		{
			s2.push(Root);
			Root = Root->lchild;
		}
		BiTNode2<Q>* top = s2.top();//ȡջ���ڵ㣺�ȱ���ýڵ�
		cout << top->data << " ";
		s2.pop();
		Root = top->rchild;
	}
	return TRUE;
}



//�ǵݹ�����������ڵ�->�ҽڵ�->���ڵ㣩˼�룺����ջʵ��  
//��1���ڵ�ǰ�ڵ�cur��Ϊ�ջ�ջ��Ϊ�յ������£��ڸ������µ�ԭ�򣺸�����˵��δ���������������  
//��2���ӵ�ǰ�ڵ�cur��ʼ����curΪѭ����������cur��Ϊ��ʱ����cur��ջ��Ȼ����cur=cur->_left������ֱ��  
//     ���ö�����������ڵ���ջ����ջ����������ȡջ���ڵ�top���ȱ���ýڵ㣨��top����ýڵ��ԭ��  
//     ��Ҫ���Ǹýڵ���Һ��ӣ���  
//��3����top->_right==NULL || lastVisited == top->_right,�����top->_value,ִ��ջ��pop����,��ִ��lastVisited = top(  
//    ��lastVisited�������һ��������Ľڵ㣬������һ��ͬ���Ĳ���ʱ����lastVisited == top->_right����  
//    ˵��top���ҽڵ��Ѿ����ʹ��ˣ����Է���top�ˣ����������cur = top->_right�ⲽ�����;  
//��4����������3�������㣬�������top->_rightΪcurֵ��ת��1������.  
template<typename Q>
Status AVLTree<Q>::PostOrder2(BiTNode2<Q>* Root)//��������ķǵݹ�ʵ��
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
