// �˰��� 1����
//�ڷᱸ�� ����_Ʈ�� ����_ ����
/*���ǻ���_ �������� �Ҵ��ؾ���, 
�������� �Ҵ��ҽ�_ Ʈ���� ũ��� ������ ������ Ÿ�ӿ� �����Ǳ� ������, ��带 ����, ���� ���
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode2 {
	int data;
	struct TreeNode2* left, * right;
}TreeNode2;

//Ʈ����带 �������� �Ҵ��ϴ� �Լ�
TreeNode2* CreateNode(int data) {
	TreeNode2* newNode = (TreeNode2*)malloc(sizeof(TreeNode2));	//Ʈ����常ŭ�� �޸� �����Ҵ�
	
	if (newNode == NULL) {
		printf("���� �޸� �Ҵ� ����");
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}

//Ʈ���� ��� ���� �Լ�
TreeNode2* insert(TreeNode2* root, int data) {
	if (root == NULL) {
		return CreateNode(data);
	}

	if (data < root->data) {	//���� ���� ��Ʈ���� ������ ��
		root->left = insert(root->left, data);	//���ʿ� �ɾ���
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);	//�����ʿ� �ɾ���
	}

	return root;
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

void preorder(TreeNode2* root) {	//������ȸ>> �߿޿�

	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


TreeNode2* MinNode(TreeNode2* root) {

	TreeNode2* min = root;

	while (min->left != NULL)	//���� Ʈ������ ���� ���� ��
		min = min->left;
	return min;
}

//�����Լ�
/*
1. ���� ��尡 �ܸ�����϶�
2. ���� ��尡 ��ܸ� ��� && �ڽ��� �Ѱ��϶�
3. ���� ��尡 ��ܸ� ��� && �ڽ��� �ΰ��϶�
*/

TreeNode2* DeleteNode(TreeNode2* root, int key) {
	
	if (root == NULL) { 
		printf("������ �� %d �� Ʈ���� �������� �ʽ��ϴ�.\n", key);
		return NULL; 
	}	//root ���� ��������� NULL ����������

	if (key < root->data) {			//Ű�� ��Ʈ���� ������ ���� Ʈ�� Ž��
		root->left = DeleteNode(root->left, key);
	}

	else if (key > root->data) {	//Ű�� ��Ʈ���� ũ�� ������ Ʈ�� Ž��
		root->right = DeleteNode(root->right, key);
	}

	else {		//else�� root->data == key �� ���

		//ù��°, �ι�° ���
		if (root->left == NULL) {	//������ �Լ��� ������ ���������	
			TreeNode2* tmp = root->right;	//������ �� ����
			free(root);	//�̿��� ���� ������
			return tmp;	//������ ���� ����������, ������ ���� �ƴϴ�
		}
		//ù��°, �ι�° ���
		else if (root->right == NULL) {	//������ �Լ��� �������� ���������	
			TreeNode2* tmp = root->left;
			free(root);
			return tmp;
		}
		//����° ���
		
		TreeNode2* tmp = MinNode(root->right);		//������ Ʈ������ ���� ���� ���� ã�� ���ؼ�
		
		root->data = tmp->data;	//����� �����͸� ������ ����� �����Ϳ� ����
		root->right = DeleteNode(root->right, tmp->data);	//ù��°, �ι�° ��쿡 �ش�Ǿ ������, ���� ��ġ�� �ִ� �� ����
	}
	
	return root;	
}


/*
void inorder(TreeNode2* root) {	//������ȸ>> ���߿�

	if (root != NULL) {

		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode2* root) {	//������ȯ_ �޿���
	// BA HGI D
	if (root != NULL) {
		postorder(root->left);  //��
		postorder(root->right);  //��
		printf("%d ", root->data);  //��
	}
}
*/

//�޸� ����
void FreeTree(TreeNode2* root) {
	if (root == NULL) {
		return;
	}

	FreeTree(root->left);
	FreeTree(root->right);

	free(root);
}

int main() {

	TreeNode2* root = NULL;

	/*
       3
     / \
    2   4
   /     \
  1       5
           \
            6
   */

	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	

	printf("���� �Լ� ���� ���� ���� Ʈ�� ���-> "); preorder(root);
	//printf("������ȸ");inorder(root);
	//printf("������ȯ");postorder(root);

	int delete;
	
	printf("\n������ ��尪�� �Է��Ͻÿ�->\n");
	scanf("%d", &delete);

	root = DeleteNode(root, delete);

	/*>> can't be working
	if (root == NULL) {
		printf("%d ���� ���̶� ��������\n", delete);
	}
	else {
		printf("%d ������\n", delete);
		printf("���� ���� ���� ��ȸ Ʈ�� ���-> ");
		preorder(root);
	}
	*/
	printf("���� �Լ� ���� ���� ���� ��ȸ Ʈ�� ���-> ");
	preorder(root);
	// �޸� ����
	
	FreeTree(root);
	
}
	
