// �˰��� 1����
//�ڷᱸ�� ����_Ʈ�� ����

#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

/*
		 D(6)
	   /     \
	  A(4)    G(5)
	 /       /  \
   B(1)   H(2)  I(3)

*/

ll

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