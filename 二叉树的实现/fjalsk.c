typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		root->_left = BinaryTreeCreate(a,n, pi);
		root->_right = BinaryTreeCreate(a,n, pi);
	}
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		BinaryTreeDestory(root->left);
		BinaryTreeDestory(root->right);
		free(root);
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* temp = BinaryTreeFind(root->_left, x);
	if (temp != NULL)
	{
		return temp;
	}
	return BinaryTreeFind(root->_right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
    while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			break;
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
}