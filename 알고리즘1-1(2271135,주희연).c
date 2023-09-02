// 알고리즘 1주차
//자료구조 복습_트리 구현

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;

// 원형큐 만들기

#define MAX_QUEUE_SIZE 100

typedef TreeNode* element; //트리노드의 포인터를 나타내는 element

typedef struct {
	
	element data[MAX_QUEUE_SIZE];
	int front, rear;

}QueueType;

void init(QueueType* q) {  //초기화
	
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) { //공백인지 확인

	return (q->front == q->rear);
	//front랑 rear 값이 같으면 1(참)반환 틀리면 0(거짓)
}

int is_full(QueueType* q) {

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

	/*예시 >> MAX_QUEUE_SIZE가 5일때, 
	
	1.
	front = 0, rear = 0
	rear 값은 (0+1)%5 = 1이 됨. front는 0이니까 값이 다르니 0반환 

	2.
	front = 0, rear = 1
	rear 값은 (1+1)%5 = 2이 됨. front는 0이니까 값이 다르니 0반환
	
	3.
	front = 0, rear = 2
	rear 값은 (2+1)%5 = 3이 됨. front는 0이니까 값이 다르니 0반환

	4.
	front = 0, rear = 4
	rear 값은 (4+1)%5 = 0이 됨. front는 0이니까 값이 같으니 1반환

	**memo**
	* (0+1)%5 = 1%5의 값은 1가 됨.(몫이 0이고 1이 나머지)
	* (1+1)%5 = 2%5의 값은 2가 됨.(몫이 0이고 2이 나머지)
	*/
}

void enqueue(QueueType* q, element item) { //삽입

	if (is_full(q)) {
		printf("큐가 꽉 차서 자리가 없음");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //원형큐니까 
	q->data[q->rear] = item; //data도 자리 옮기기
	//return 0; //삽입 성공
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("큐가 전부 비어서 삭제할 자리가 없음");
		return NULL;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	//q->data[q->front] == NULL;  //data도 삭제하기__ 추후 수정될수 있음__삭제하면 반환 못함
	return q->data[q->front];
	//반환형식 element로 변경
}

// 원형큐 만들기 끝

//레벨 순회하기

void levelorder(TreeNode* ptr) {

	QueueType q;  //원형큐 선언
	init(&q);	//사용하기 위해서 초기화
	
	if (ptr == NULL)return;

	enqueue(&q, ptr);  // 트리 n6 값 넣기

	while (!is_empty(&q)) { //비어있지 않으면 계속 돌아감

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

//레벨 순회 끝하기

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
	levelorder(root);
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