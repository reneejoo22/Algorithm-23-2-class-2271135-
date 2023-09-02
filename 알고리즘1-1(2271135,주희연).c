// �˰��� 1����
//�ڷᱸ�� ����_Ʈ�� ����

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

// ����ť �����

#define MAX_QUEUE_SIZE 100

typedef TreeNode* element; //Ʈ������� �����͸� ��Ÿ���� element

typedef struct {
	
	element data[MAX_QUEUE_SIZE];
	int front, rear;

}QueueType;

void init(QueueType* q) {  //�ʱ�ȭ
	
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) { //�������� Ȯ��

	return (q->front == q->rear);
	//front�� rear ���� ������ 1(��)��ȯ Ʋ���� 0(����)
}

int is_full(QueueType* q) {

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

	/*���� >> MAX_QUEUE_SIZE�� 5�϶�, 
	
	1.
	front = 0, rear = 0
	rear ���� (0+1)%5 = 1�� ��. front�� 0�̴ϱ� ���� �ٸ��� 0��ȯ 

	2.
	front = 0, rear = 1
	rear ���� (1+1)%5 = 2�� ��. front�� 0�̴ϱ� ���� �ٸ��� 0��ȯ
	
	3.
	front = 0, rear = 2
	rear ���� (2+1)%5 = 3�� ��. front�� 0�̴ϱ� ���� �ٸ��� 0��ȯ

	4.
	front = 0, rear = 4
	rear ���� (4+1)%5 = 0�� ��. front�� 0�̴ϱ� ���� ������ 1��ȯ

	**memo**
	* (0+1)%5 = 1%5�� ���� 1�� ��.(���� 0�̰� 1�� ������)
	* (1+1)%5 = 2%5�� ���� 2�� ��.(���� 0�̰� 2�� ������)
	*/
}

void enqueue(QueueType* q, element item) { //����

	if (is_full(q)) {
		printf("ť�� �� ���� �ڸ��� ����");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //����ť�ϱ� 
	q->data[q->rear] = item; //data�� �ڸ� �ű��
	//return 0; //���� ����
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("ť�� ���� �� ������ �ڸ��� ����");
		return NULL;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	//q->data[q->front] == NULL;  //data�� �����ϱ�__ ���� �����ɼ� ����__�����ϸ� ��ȯ ����
	return q->data[q->front];
	//��ȯ���� element�� ����
}

// ����ť ����� ��

//���� ��ȸ�ϱ�

void levelorder(TreeNode* ptr) {

	QueueType q;  //����ť ����
	init(&q);	//����ϱ� ���ؼ� �ʱ�ȭ
	
	if (ptr == NULL)return;

	enqueue(&q, ptr);  // Ʈ�� n6 �� �ֱ�

	while (!is_empty(&q)) { //������� ������ ��� ���ư�

		ptr = dequeue(&q); 
		printf("%c ", ptr->data);
		
		if (ptr->left) {
			enqueue(&q, ptr->left);
		}

		if (ptr->right) {
			enqueue(&q, ptr->right);
		}

	}

}

//���� ��ȸ ���ϱ�

/*
		 D(6)
	   /     \
	  A(4)   G(5)
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
	levelorder(root);
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