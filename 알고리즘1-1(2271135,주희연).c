// �ñ��

// �˰��� 1����
//�ڷᱸ�� ����_Ʈ�� ����_ Ž��

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

/*
* ���� �����ͷ� ������ Ʈ��
		 D(6)
	   /     \
	  A(4)    G(5)
	 /       /  \
   B(1)   H(2)  I(3)
   */


TreeNode m1 = { 'B',NULL,NULL };
TreeNode m2 = { 'H',NULL,NULL };
TreeNode m3 = { 'I',NULL,NULL };
TreeNode m4 = { 'A',&m1,NULL };
TreeNode m5 = { 'G',&m2, &m3 };
TreeNode m6 = { 'D',&m4,&m5 };

TreeNode *root = &m6;


typedef struct TreeNode2 {
	int data;
	struct TreeNode2* left, * right;
}TreeNode2;

/*
 ���� �����ͷ� ������ Ʈ��
		 D(6)
	   /     \
	  A(4)    G(5)
	 /       /  \
   B(1)   H(2)  I(3)
   */

TreeNode2 n1 = { 1,NULL,NULL };
TreeNode2 n2 = { 2,NULL,NULL };
TreeNode2 n3 = { 3,NULL,NULL };
TreeNode2 n4 = { 4,&n1,NULL };
TreeNode2 n5 = { 5,&n2, &n3 };
TreeNode2 n6 = { 6 ,&n4,&n5 };

TreeNode2* roott = &n6;

//TreeNode (����)Ž�� �Լ�
/*
 �ΰ��� ���
 1. �������� ��Ʈ���� ũ�ų� ���� ���
 2. �������� ��Ʈ�� ���� ��ġ�ϴ� ���
 **��Ʈ�� �� ���� �ƴ��� Ȯ��

 �Ʒ� ����� �ݺ����� ���
*/

TreeNode* search(TreeNode* root, char item) {

	TreeNode* tmp = root;

	while (tmp != NULL) {
		if (item == tmp->data)return tmp; //��Ʈ���� �ٷ� ã���� �� ��ȯ
		else if (item < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return NULL;
}

//TreeNode2 (����)Ž�� �Լ�
/*
 �ΰ��� ���
 1. �������� ��Ʈ���� ũ�ų� ���� ���
 2. �������� ��Ʈ�� ���� ��ġ�ϴ� ���
 **��Ʈ�� �� ���� �ƴ��� Ȯ��

 �Ʒ� ����� ��ȯ���� ���
*/

int explore2(int item, TreeNode2* root) {	//���ڿ�

	if (root == NULL)return 0;	//��Ʈ ���� �ƹ��͵� ������ ����������

	if (root->data == item)return 1;	// �Է¹��� root�� item�̶� �ٷ� ��ġ�ϸ� True ����������

	if (root->data > item) {
		return explore2(item, root->left);
	}
	else {
		return explore2(item, root->right);
	}
}


int main() {

	// explore �̿�
	char find;

	printf("Ž���� ���� �Է�-> ");
	scanf("%c", &find);

	if (NULL != search(&m6, find)) {
		printf("%c ã��\n", find);
	}
	else printf("%c ����\n", find);

	// explore 2 �̿�/////////////////////////

	int finding;

	printf("Ž���� �� �Է�-> ");
	scanf("%d", &finding);
	//printf("%d �Է¹���", finding);
	
	int result2 = explore2(finding, &n6);

	if (result2 == 1) {
		printf("%d ã��", finding);
	}
	else { printf("%d ����", finding); }

}
	
