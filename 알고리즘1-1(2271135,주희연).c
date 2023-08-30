//트리 복습

/*
공식

-노드 n, 간선 n-1 >> 루트 노드 제외 모두 부모 트리 가짐
-높이, 최대 n, 최소 log(n+1)

-인덱스, 부모 노드 i/2, 왼 자식 2i, 오른 자식 2i+1

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *right, *left;
}TreeNode;

/*
	n1
	/

*/
TreeNode n1{ 1, NULL, NULL };