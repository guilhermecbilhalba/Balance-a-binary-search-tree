#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int				val;
	struct TreeNode*	left;
	struct TreeNode*	right;
} treeNode_t;


treeNode_t* CriaNo( int valor ) {
	treeNode_t* tree = malloc( sizeof( treeNode_t ) );
	tree->val = valor;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}


int Altura( treeNode_t* root ) {
	if ( root == NULL ) {
		return 0;
	}
	
	int alturaEsquerda = Altura( root->left );
	int alturaDireita = Altura( root->right );
	int maior;
	
	if ( alturaEsquerda > alturaDireita ) {
		maior = alturaEsquerda;
	} else {
		maior = alturaDireita;
	}
	
	return maior + 1;
}


int IsBalanced( treeNode_t* root ) {
	if ( !root ) {
		return 0;
	}
	
	int countleft = Altura( root->left );
	int countright = Altura( root->right );
	
	if ( countleft - countright > 1 ) {
	return 1;
	
	if ( countright - countleft > 1 ) {
		return 2;
	}
	
	return 0;
}
}

void PreencherInorder( treeNode_t* root, int* arr, int* index ) {
	if ( !root ) {
		return;
	}
	
	PreencherInorder( root->left, arr, index );
	arr[(*index)++] = root->val;
	PreencherInorder( root->right, arr, index );
}


treeNode_t* MontarBalanceada( int* arr, int inicio, int fim ) {
	if ( inicio > fim ) {
		return NULL;
	}
	
	int meio = ( inicio + fim ) / 2;
	treeNode_t* node = CriaNo( arr[meio] );
	node->left = MontarBalanceada( arr, inicio, meio - 1 );
	node->right = MontarBalanceada( arr, meio + 1, fim );
	
	return node;
}


treeNode_t* BalanceBST( treeNode_t* root ) {
	int balance = IsBalanced( root );
	
	if ( balance == 0 ) {
		return root;
	} else {
		int valores[1000];
		int index = 0;
		
		PreencherInorder( root, valores, &index );
		treeNode_t* nova = MontarBalanceada( valores, 0, index - 1 );
		
		return nova;
	}
}


void PrintInorder( treeNode_t* root ) {
	if ( !root ) {
		return;
	}
	
	PrintInorder( root->left );
	printf( "%d ", root->val );
	PrintInorder( root->right );
}


void FreeTree( treeNode_t* root ) {
	if ( !root ) {
		return;
	}
	
	FreeTree( root->left );
	FreeTree( root->right );
	free( root );
}

int main( void ) {
	treeNode_t* tree = CriaNo( 10 );
	tree->right = CriaNo( 20 );
	tree->right->right = CriaNo( 30 );
	tree->right->right->right = CriaNo( 40 );
	tree->right->right->right->right = CriaNo( 50 );
	
	printf( "Antes de balancear (in-order):\n" );
	PrintInorder( tree );
	printf( "\n" );
	
	treeNode_t* balanceada = BalanceBST( tree );
	
	printf( "Depois de balancear (in-order):\n" );
	PrintInorder( balanceada );
	printf( "\n" );
	
	FreeTree( tree );
	FreeTree( balanceada );
	
	return 0;
}
