//Ʈ�� ����

/*
����

-��� n, ���� n-1 >> ��Ʈ ��� ���� ��� �θ� Ʈ�� ����
-����, �ִ� n, �ּ� log(n+1)

-�ε���, �θ� ��� i/2, �� �ڽ� 2i, ���� �ڽ� 2i+1

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