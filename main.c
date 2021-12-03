#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node *left;
    struct node *right;
};

struct node *mknode(int x, struct node *left, struct node* right);
struct node* perfect_tree(int h);
void print_infix(struct node *n);
void free_tree(struct node *n);
int find(int i, struct node *abr);
struct node *insert(int i, struct node *abr);

int
main() {
    struct node* abr;
    int k, v;
    
    printf("How many nodes for your binary search tree ? ");
    scanf("%d", &k);
    printf("node_0 = ");
    scanf("%d", &v);
    abr = mknode(v, NULL, NULL);
    for(int i = 1 ; i < k ; i++) {
	printf("node_%d = ", i);
	scanf("%d", &v);
	insert(v, abr);
    }
    printf("What value would you like to find ?  ");
    scanf("%d", &k);
    if(find(k, abr) == 1) {
	printf("Found !\n");
    } else if(find(k, abr) == 0) {
	printf("Error 404 : not found !\n");
    }
    print_infix(abr);
    free_tree(abr);

	
    
    return 0;
}

struct node *mknode(int x, struct node *left, struct node* right) {
    struct node* p = malloc(sizeof(struct node));
    if(p == NULL)
	return NULL;
    p->v = x;
    p->left = left;
    p->right = right;
    return p;
}

struct node* perfect_tree(int h) {
    if(h == 0) {
	return NULL;
    }
    return mknode(1, perfect_tree(h-1), perfect_tree(h-1));
}

void print_infix(struct node *n) {
    if(n == NULL) {
	return;
    }
    if(n->left == NULL && n->right == NULL) {
	printf("%d\n", n->v);
    } else if(n->left != NULL) {
	print_infix(n->left);
	printf("%d\n", n->v);
	print_infix(n->right);
    } else {
	print_infix(n->right);
	printf("%d\n", n->v);
    }
}

void free_tree(struct node *n) {
    if(n == NULL) {
	return;
    }
    free_tree(n->left);
    free_tree(n->right);
    free(n);
}

int find(int i, struct node *abr) {
    struct node* current = abr;
    while(1) {
	if(i < current->v) {
	    if(current->left != NULL) {
		current = current->left;
	    } else {
		return 0;
	    }
	} else if(i > current->v) {
	    if(current->right != NULL) {
		current = current->right;
	    } else {
		return 0; 
	    }
	} else {
	    return 1;
	}
    }
}

struct node *insert(int i, struct node *abr) {
    struct node* current = abr;
    if(find(i, abr) == 1) {
	return NULL;
    }
    while(1) {
	if(i < current->v) {
	    if(current->left != NULL) {
		current = current->left;
	    } else {
		current->left = mknode(i, NULL, NULL);
		return current->left; //"La racine du nouvel arbre"
	    }
	} else if(i > current->v) {
	    if(current->right != NULL) {
		current = current->right;
	    } else {
		current->right = mknode(i, NULL, NULL);
		return current->right; //"La racine du nouvel arbre"
	    }
	} else {
	    return NULL;
	}
    }
}




