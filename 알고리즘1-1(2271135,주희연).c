//트리 복습

/*
공식

- 노드 n, 간선 n-1 >> 루트 노드 제외 모두 부모 트리 가짐
- 높이, 최대 n, 최소 log(n+1)

- 인덱스, 부모 노드 i/2, 왼 자식 2i, 오른 자식 2i+1

이진 탐색트리
- 왼<중<오
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define num1 100
#define num2 200

typedef struct {
	
	char word[num1];
	char mean[num2];
};

typedef struct TreeNode {
	int data;
	struct TreeNode *right, *left;
}TreeNode;


/*


*/


// 1차 정정 
// 내용 추가