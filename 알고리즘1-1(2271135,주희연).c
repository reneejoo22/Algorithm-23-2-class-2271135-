//Ʈ�� ����

/*
����

- ��� n, ���� n-1 >> ��Ʈ ��� ���� ��� �θ� Ʈ�� ����
- ����, �ִ� n, �ּ� log(n+1)

- �ε���, �θ� ��� i/2, �� �ڽ� 2i, ���� �ڽ� 2i+1

���� Ž��Ʈ��
- ��<��<��
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


// 1�� ���� 
// ���� �߰�