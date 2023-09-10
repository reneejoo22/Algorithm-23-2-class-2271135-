// 알고리즘 1주차
//자료구조 복습_트리 구현_ 삭제
/*주의사항_ 동작으로 할당해야함, 
정적으로 할당할시_ 트리의 크기와 구조가 컴파일 타임에 고정되기 때문에, 노드를 삭제, 변경 어렵
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode2 {
	int data;
	struct TreeNode2* left, * right;
}TreeNode2;

//트리노드를 동적으로 할당하는 함수
TreeNode2* CreateNode(int data) {
	TreeNode2* newNode = (TreeNode2*)malloc(sizeof(TreeNode2));	//트리노드만큼의 메모리 동적할당
	
	if (newNode == NULL) {
		printf("동적 메모리 할당 오류");
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;

}

//트리에 노드 삽입 함수
TreeNode2* insert(TreeNode2* root, int data) {
	if (root == NULL) {
		return CreateNode(data);
	}

	if (data < root->data) {	//받은 값이 루트보다 작으면 왼
		root->left = insert(root->left, data);	//왼쪽에 심어줌
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);	//오른쪽에 심어줌
	}

	return root;
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

void preorder(TreeNode2* root) {	//전위순회>> 중왼오

	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


TreeNode2* MinNode(TreeNode2* root) {

	TreeNode2* min = root;

	while (min->left != NULL)	//왼쪽 트리에서 제일 작은 값
		min = min->left;
	return min;
}

//삭제함수
/*
1. 삭제 노드가 단말노드일때
2. 삭제 노드가 비단말 노드 && 자식이 한개일때
3. 삭제 노드가 비단말 노드 && 자식이 두개일때
*/

TreeNode2* DeleteNode(TreeNode2* root, int key) {
	
	if (root == NULL) { 
		printf("삭제할 값 %d 가 트리에 존재하지 않습니다.\n", key);
		return NULL; 
	}	//root 값이 비어있으면 NULL 돌려보내기

	if (key < root->data) {			//키가 루트보다 작으면 왼쪽 트리 탐색
		root->left = DeleteNode(root->left, key);
	}

	else if (key > root->data) {	//키가 루트보다 크면 오른쪽 트리 탐색
		root->right = DeleteNode(root->right, key);
	}

	else {		//else는 root->data == key 인 경우

		//첫번째, 두번째 경우
		if (root->left == NULL) {	//삭제할 함수의 왼쪽이 비어있을때	
			TreeNode2* tmp = root->right;	//오른쪽 값 저장
			free(root);	//이외의 값은 없애줌
			return tmp;	//오른쪽 값은 돌려보내줌, 삭제할 값이 아니니
		}
		//첫번째, 두번째 경우
		else if (root->right == NULL) {	//삭제할 함수의 오른쪽이 비어있을때	
			TreeNode2* tmp = root->left;
			free(root);
			return tmp;
		}
		//세번째 경우
		
		TreeNode2* tmp = MinNode(root->right);		//오른쪽 트리에서 제일 작은 값을 찾기 위해서
		
		root->data = tmp->data;	//노드의 데이터를 삭제할 노드의 데이터에 넣음
		root->right = DeleteNode(root->right, tmp->data);	//첫번째, 두번째 경우에 해당되어서 삭제됨, 이전 위치에 있던 건 삭제
	}
	
	return root;	
}


/*
void inorder(TreeNode2* root) {	//중위순회>> 왼중오

	if (root != NULL) {

		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode2* root) {	//후위순환_ 왼오중
	// BA HGI D
	if (root != NULL) {
		postorder(root->left);  //왼
		postorder(root->right);  //오
		printf("%d ", root->data);  //중
	}
}
*/

//메모리 해제
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
	

	printf("삭제 함수 실행 전의 전위 트리 모습-> "); preorder(root);
	//printf("중위순회");inorder(root);
	//printf("후위순환");postorder(root);

	int delete;
	
	printf("\n삭제할 노드값을 입력하시오->\n");
	scanf("%d", &delete);

	root = DeleteNode(root, delete);

	/*>> can't be working
	if (root == NULL) {
		printf("%d 없는 값이라서 삭제못함\n", delete);
	}
	else {
		printf("%d 삭제함\n", delete);
		printf("삭제 후의 전위 순회 트리 모습-> ");
		preorder(root);
	}
	*/
	printf("삭제 함수 실행 후의 전위 순회 트리 모습-> ");
	preorder(root);
	// 메모리 해제
	
	FreeTree(root);
	
}
	
