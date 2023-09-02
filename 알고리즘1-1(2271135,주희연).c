// �˰��� 1����
//�ڷᱸ�� ����_Ʈ�� ����
//������ȯ_ ����ť�� �ƴ϶� ���߿��Ḯ��Ʈ ����غ���

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

//���߿��� ����Ʈ ����///////////////////////

// ���� ���� ����Ʈ ��� ����ü ����
typedef struct DLinkedNode {
	TreeNode* data;		//���� �� �ִ� �����͸� Ʈ����� �����ͷ�
	struct DLinkedNode* prev;	//���� �ּ���
	struct DLinkedNode* next;	//���� �ּ���
} DLinkedNode;

// ���� ���� ����Ʈ �ʱ�ȭ �Լ�
void init(DLinkedNode* d) {
	d->prev = d->next = d;
}

// ���� ���� ����Ʈ�� ��� ���� �Լ�
void dinsert(DLinkedNode* before, TreeNode* data) {

	DLinkedNode* newnode = (DLinkedNode*)malloc(sizeof(DLinkedNode));
	newnode->data = data;	//�� ��忡 ��������� ������ �� �ֱ�

	newnode->prev = before;		//1�ܰ�_ ������� ������ before�� �����Ѿߵ�
	newnode->next = before->next;  //2�ܰ�_ ������� ���Ĵ� before�� ����Ű�� ���ĸ� �����Ѿߵ�

	before->next->prev = newnode;	//3�ܰ�_ ������� �ճ�尡 ��ü�� ��. �ճ���� ������ �� ��带 ����Ŵ
	before->next = newnode;		//4�ܰ�_ ���� ����� ������ ����带 ����Ŵ
}

// ���� ���� ����Ʈ���� ��� ���� �Լ�
TreeNode* ddelete(DLinkedNode* node) {

	if (node->prev == node) {	//�ڽŸ� �ִٴ� ��
		return NULL; // ����Ʈ�� ��� �ִ� ���
	}

	TreeNode* data = node->data;	//������ ����� �����͸� ������

	node->prev->next = node->next;	//1�ܰ�_ ������ ����� ���� ��尡 ��ü�� ��. ������ ����Ŵ
	node->next->prev = node->prev; //2�ܰ�_ ������ ����� ���� ��尡 ��ü�� ��. ������ ����Ŵ
	free(node);

	return data;  //�� �Ѱ���
}
//���߿��� ����Ʈ ��

// Ʈ���� ���� ��ȸ �Լ�
void LevelOrder(TreeNode* root) {

	if (root == NULL) {
		return;
	}

	DLinkedNode head;
	init(&head);
	dinsert(&head, root);	//n6�� �ֱ�

	while (head.next != &head) {	//��尡 �ϳ��� ���� �ʾҴٸ� ��� �ݺ�
		TreeNode* current_data = ddelete(head.next);	//������ �� �����ϰ�
		printf("%c ", current_data->data);	//���

		if (current_data->left) {	//���� ��ȯ
			dinsert(head.prev, current_data->left);
		}

		if (current_data->right) {
			dinsert(head.prev, current_data->right);
		}
	}
}

//������ȸ ��

/*
		 D(6)
	   /     \
	  A(4)    G(5)
	 /       /  \
   B(1)   H(2)  I(3)

*/

TreeNode n1 = { 'B',NULL,NULL };
TreeNode n2 = { 'H',NULL,NULL };
TreeNode n3 = { 'I',NULL,NULL };
TreeNode n4 = { 'A',&n1,NULL };
TreeNode n5 = { 'G',&n2, &n3 };
TreeNode n6 = { 'D',&n4,&n5 };

TreeNode *root = &n6;

void preorder(TreeNode* root) {	//������ȯ_ �߿޿�
	// D AB GHI
	if (root != NULL) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root) {	//������ȯ_ ���߿�
	// 
	if (root != NULL) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root) {	//������ȯ_ �޿���
	// BA HGI D
	if (root != NULL) {
		postorder(root->left);  //��
		postorder(root->right);  //��
		printf("%c ", root->data);  //��
	}
}



int main() {

	printf("������ȯ\n");
	preorder(root);
	printf("\n");

	printf("������ȯ\n");
	inorder(root);
	printf("\n");

	printf("������ȯ\n");
	postorder(root);
	printf("\n");

	printf("������ȯ\n");
	LevelOrder(root);
	printf("\n");
}

//Ʈ�� ����

/*
����

- ��� n, ���� n-1 >> ��Ʈ ��� ���� ��� �θ� Ʈ�� ����
- ����, �ִ� n, �ּ� log(n+1)

- �ε���, �θ� ��� i/2, �� �ڽ� 2i, ���� �ڽ� 2i+1

���� Ž��Ʈ��
- ��<��<��
*/