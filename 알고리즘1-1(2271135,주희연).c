// 알고리즘 1주차
//자료구조 복습_트리 구현
//레벨순환_ 원형큐가 아니라 이중연결리스트 사용해보기

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

//이중연결 리스트 시작///////////////////////

// 이중 연결 리스트 노드 구조체 정의
typedef struct DLinkedNode {
	TreeNode* data;		//받을 수 있는 데이터를 트리노드 포인터로
	struct DLinkedNode* prev;	//이전 주소지
	struct DLinkedNode* next;	//이후 주소지
} DLinkedNode;

// 이중 연결 리스트 초기화 함수
void init(DLinkedNode* d) {
	d->prev = d->next = d;
}

// 이중 연결 리스트에 요소 삽입 함수
void dinsert(DLinkedNode* before, TreeNode* data) {

	DLinkedNode* newnode = (DLinkedNode*)malloc(sizeof(DLinkedNode));
	newnode->data = data;	//새 노드에 멤버변수의 데이터 값 넣기

	newnode->prev = before;		//1단계_ 새노드의 이전은 before를 가르켜야됨
	newnode->next = before->next;  //2단계_ 새노드의 이후는 before가 가르키던 이후를 가르켜야됨

	before->next->prev = newnode;	//3단계_ 뉴노드의 앞노드가 주체가 됨. 앞노드의 이전은 뉴 노드를 가르킴
	before->next = newnode;		//4단계_ 이전 노드의 다음이 뉴노드를 가르킴
}

// 이중 연결 리스트에서 요소 삭제 함수
TreeNode* ddelete(DLinkedNode* node) {

	if (node->prev == node) {	//자신만 있다는 뜻
		return NULL; // 리스트가 비어 있는 경우
	}

	TreeNode* data = node->data;	//삭제할 노드의 데이터를 저장함

	node->prev->next = node->next;	//1단계_ 삭제할 노드의 이전 노드가 주체가 됨. 다음을 가르킴
	node->next->prev = node->prev; //2단계_ 삭제할 노드의 이후 노드가 주체가 됨. 이전을 가르킴
	free(node);

	return data;  //값 넘겨줌
}
//이중연결 리스트 끝

// 트리의 레벨 순회 함수
void LevelOrder(TreeNode* root) {

	if (root == NULL) {
		return;
	}

	DLinkedNode head;
	init(&head);
	dinsert(&head, root);	//n6값 넣기

	while (head.next != &head) {	//노드가 하나만 남지 않았다면 계속 반복
		TreeNode* current_data = ddelete(head.next);	//삭제할 값 저장하고
		printf("%c ", current_data->data);	//출력

		if (current_data->left) {	//왼쪽 순환
			dinsert(head.prev, current_data->left);
		}

		if (current_data->right) {
			dinsert(head.prev, current_data->right);
		}
	}
}

//레벨순회 끝

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

	printf("레벨순환\n");
	LevelOrder(root);
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