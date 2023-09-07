// 올기긱

// 알고리즘 1주차
//자료구조 복습_트리 구현_ 탐색

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

/*
* 영어 데이터로 구성된 트리
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
 숫자 데이터로 구성된 트리
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

//TreeNode (문자)탐색 함수
/*
 두가지 경우
 1. 아이템이 루트보다 크거나 작은 경우
 2. 아이템이 루트와 값이 일치하는 경우
 **루트가 빈 값이 아닌지 확인

 아래 방식은 반복적인 방식
*/

TreeNode* search(TreeNode* root, char item) {

	TreeNode* tmp = root;

	while (tmp != NULL) {
		if (item == tmp->data)return tmp; //루트에서 바로 찾으면 값 반환
		else if (item < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return NULL;
}

//TreeNode2 (숫자)탐색 함수
/*
 두가지 경우
 1. 아이템이 루트보다 크거나 작은 경우
 2. 아이템이 루트와 값이 일치하는 경우
 **루트가 빈 값이 아닌지 확인

 아래 방식은 순환적인 방식
*/

int explore2(int item, TreeNode2* root) {	//숫자용

	if (root == NULL)return 0;	//루트 값에 아무것도 없으면 돌려보내기

	if (root->data == item)return 1;	// 입력받은 root가 item이랑 바로 일치하면 True 돌려보내기

	if (root->data > item) {
		return explore2(item, root->left);
	}
	else {
		return explore2(item, root->right);
	}
}


int main() {

	// explore 이용
	char find;

	printf("탐색할 문자 입력-> ");
	scanf("%c", &find);

	if (NULL != search(&m6, find)) {
		printf("%c 찾음\n", find);
	}
	else printf("%c 없음\n", find);

	// explore 2 이용/////////////////////////

	int finding;

	printf("탐색할 수 입력-> ");
	scanf("%d", &finding);
	//printf("%d 입력받음", finding);
	
	int result2 = explore2(finding, &n6);

	if (result2 == 1) {
		printf("%d 찾음", finding);
	}
	else { printf("%d 없음", finding); }

}
	
