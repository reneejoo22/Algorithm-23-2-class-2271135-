// 알고리즘 1주차
//자료구조 복습_트리 구현

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

void preorder(TreeNode* root) {	//전위순환_ 중왼오
	// D AB GHI
	if (root != NULL) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root) {	//중위순환_ 왼중오
	// 
	if (root != NULL) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root) {	//후위순환_ 왼오중
	// BA HGI D
	if (root != NULL) {
		postorder(root->left);  //왼
		postorder(root->right);  //오
		printf("%c ", root->data);  //중
	}
}



int main() {

	printf("전위순환\n");
	preorder(root);
	printf("\n");

	printf("중위순환\n");
	inorder(root);
	printf("\n");

	printf("후위순환\n");
	postorder(root);
	printf("\n");
}

//트리 복습

/*
공식

- 노드 n, 간선 n-1 >> 루트 노드 제외 모두 부모 트리 가짐
- 높이, 최대 n, 최소 log(n+1)

- 인덱스, 부모 노드 i/2, 왼 자식 2i, 오른 자식 2i+1

이진 탐색트리
- 왼<중<오
*/