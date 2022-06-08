#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define bool int

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;
}node;

struct node* initialize_node(int);
struct node* create_tree(int);
struct node* insert_into_tree(struct node*, int);
void test_insert_into_tree();
bool is_node_in(struct node*, int);
void test_node_search();
struct node* node_search(struct node*, int);
void print_tree_preorder(struct node*);
void print_tree_inorder(struct node*);
void print_tree_postorder(struct node*);
void test_print_trees();
struct node* maximum_node(struct node*);
struct node* minimum_node(struct node*);
void test_maximum_node();
void test_minimum_node();
struct node* delete_from_tree(struct node*, int);
void test_delete_from_tree();
struct node* free_tree(struct node*);
void test_free_tree();

struct node* initialize_node(int key){
    //malloc returns a void pointer, typecasting to (struct node*) is unnecessary, but it could be if we're compiling for C++ instead of C
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); //we need to allocate memory first (seg. fault otherwise)
    
    //Initializing fields
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL; 

    return new_node;
}

struct node* create_tree(int root_value){
    struct node* root = initialize_node(root_value);
    return root;
}

struct node* insert_into_tree(struct node* root, int key_value){
    if(root == NULL){
        return initialize_node(key_value);
    }else{
        if(key_value < root->key){
            root->left = insert_into_tree(root->left, key_value);
        }else{
            root->right = insert_into_tree(root->right, key_value);
        }
    return root;
    }
}

void test_insert_into_tree() {
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree, root value is a random integer;
            2 - Produce a for loop that inserts numbers into the tree (insertion method is the tester's choice);
            3 - Print the tree (use any of the print methods, this step is unnecessary for the tests)
            4 - Check to see if the children of each node are the correct ones (Recomendation: use assertions over printfs)
        --------------------------------------------
    */

    struct node* root = create_tree(11); // 1
    // 2
    for (int i = 0; i < 10; i++) {
        insert_into_tree(root, i);
    }
    // 3
    print_tree_inorder(root);

    // 4
    assert(root->key == 11);
    assert(root->left->key == 0);
    assert(root->left->right->key == 1);
    assert(root->left->right->right->key == 2);
    assert(root->left->right->right->right->key == 3);
    assert(root->left->right->right->right->right->key == 4);
    assert(root->left->right->right->right->right->right->key == 5);
    assert(root->left->right->right->right->right->right->right->key == 6);
    assert(root->left->right->right->right->right->right->right->right->key == 7);
    assert(root->left->right->right->right->right->right->right->right->right->key == 8);
    assert(root->left->right->right->right->right->right->right->right->right->right->key == 9);

    root = create_tree(21);
    for (int i = 0; i < 20; i++) {
        insert_into_tree(root, i);
    }
    assert(root->key == 21);
    assert(root->left->key == 0);
    assert(root->left->right->key == 1);
    assert(root->left->right->right->key == 2);
    assert(root->left->right->right->right->key == 3);
    assert(root->left->right->right->right->right->key == 4);
    assert(root->left->right->right->right->right->right->key == 5);
    assert(root->left->right->right->right->right->right->right->key == 6);
    assert(root->left->right->right->right->right->right->right->right->key == 7);
    assert(root->left->right->right->right->right->right->right->right->right->key == 8);
    assert(root->left->right->right->right->right->right->right->right->right->right->key == 9);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->key == 10);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->key == 11);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->key == 12);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 13);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 14);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 15);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 16);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 17);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 18);
    assert(root->left->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->right->key == 19);

    root = create_tree(11);
    int integer_list[10] = { 2, -1, 17, 55, 31, 6, 3, -5, -8, 10 };
    for (int i = 0; i < 10; i++) {
        insert_into_tree(root, integer_list[i]);
    }
    assert(root->key == 11);
    assert(root->left->key == 2);
    assert(root->left->left->key == -1);
    assert(root->left->left->left->key == -5);
    assert(root->left->left->left->left->key == -8);
    assert(root->left->right->key == 6);
    assert(root->left->right->left->key == 3);
    assert(root->left->right->right->key == 10);
    assert(root->right->key == 17);
    assert(root->right->right->key == 55);
    assert(root->right->right->left->key == 31);

    root = create_tree(21);
    int integer_list1[20] = { 5, -6, 13, 41, -19, 0, 7, 2, 100, 58,
                            18, -30, -5, 14, 15, -9, -2, 71, 11, -20 };
    for (int i = 0; i < 20; i++) {
        insert_into_tree(root, integer_list1[i]);
    }

    assert(root->key == 21);
    assert(root->left->key == 5);
    assert(root->left->left->key == -6);
    assert(root->left->left->left->key == -19);
    assert(root->left->left->left->left->key == -30);
    assert(root->left->left->left->left->right->key == -20);
    assert(root->left->left->left->right->key == -9);
    assert(root->left->left->right->key == 0);
    assert(root->left->left->right->left->key == -5);
    assert(root->left->left->right->left->right->key == -2);
    assert(root->left->left->right->right->key == 2);
    assert(root->left->right->key == 13);
    assert(root->left->right->left->key == 7);
    assert(root->left->right->left->right->key == 11);
    assert(root->left->right->right->key == 18);
    assert(root->left->right->right->left->key == 14);
    assert(root->left->right->right->left->right->key == 15);
    assert(root->right->key == 41);
    assert(root->right->right->key == 100);
    assert(root->right->right->left->key == 58);
    assert(root->right->right->left->right->key == 71);

    printf("\nAll insertion tests are done!\n");
}

bool is_node_in(struct node* root, int node_search_key){
    if (root == NULL) {
        return FALSE;
    }else{
        if(node_search_key == root->key){
            return TRUE;
        }else if (node_search_key < root->key){
            return is_node_in(root->left, node_search_key);
        }
        return is_node_in(root->right, node_search_key);
    }
}

struct node* node_search(struct node* root, int node_search_key){
    if (root == NULL || node_search_key == root->key){
        return root;
    }
    if (node_search_key < root->key){
        node_search(root->left, node_search_key);
    }else{
        node_search(root->right, node_search_key);
    }
}

void test_node_search(){
    /*
    ---------------TEST STRUCTURE---------------
        1 - Create a tree, root value is a random integer;
        2 - Insert as many nodes with random values as you want into the tree (the insertion method is up to the tester);
        3 - Print the resulted tree (use any of the print methods, this step is unnecessary for the tests)
        4 - Search for some nodes that are in the tree (using is_node_in);
        5 - Search for some nodes that are not in the tree (using is_node_in);
        6 - Search for some nodes that are in the tree (using node_search).
    --------------------------------------------
    */

    struct node* root = create_tree(10); // 1
    // 2
    int integer_list[5] = {-1, 11, 45, -19, 7};
    for(int i = 0; i < 5; i++){
        insert_into_tree(root, integer_list[i]);
    }

    print_tree_inorder(root); // 3

    // 4
    assert(is_node_in(root, 10) == TRUE);
    assert(is_node_in(root, -1) == TRUE);
    assert(is_node_in(root, 11) == TRUE);
    assert(is_node_in(root, 45) == TRUE);
    assert(is_node_in(root, -19) == TRUE);
    assert(is_node_in(root, 7) == TRUE);
    // 5
    assert(is_node_in(root, 1) == FALSE);
    assert(is_node_in(root, 300) == FALSE);
    assert(is_node_in(root, 12) == FALSE);
    assert(is_node_in(root, 44) == FALSE);
    assert(is_node_in(root, 0) == FALSE);
    assert(is_node_in(root, 1000) == FALSE);
    // 6
    assert(node_search(root, 10)->key == 10);
    assert(node_search(root, -1)->key == -1);
    assert(node_search(root, 11)->key == 11);
    assert(node_search(root, 45)->key == 45);
    assert(node_search(root, -19)->key == -19);
    assert(node_search(root, 7)->key == 7);

    root = create_tree(38);
    int integer_list2[20] = {-100, 34, 22, -58, -4, -2, 0, 67, 78, 18, 
                            19, 55, 31, 17, 15, -90, -33, -27, 76, 20};
    for (int i = 0; i < 20; i++)
    {
        insert_into_tree(root, integer_list2[i]);
    }

    print_tree_inorder(root);

    assert(is_node_in(root, -100) == TRUE);
    assert(is_node_in(root, 34) == TRUE);
    assert(is_node_in(root, 22) == TRUE);
    assert(is_node_in(root, -58) == TRUE);
    assert(is_node_in(root, -4) == TRUE);
    assert(is_node_in(root, -2) == TRUE);
    assert(is_node_in(root, 0) == TRUE);
    assert(is_node_in(root, 67) == TRUE);
    assert(is_node_in(root, 78) == TRUE);
    assert(is_node_in(root, 18) == TRUE);
    assert(is_node_in(root, 19) == TRUE);
    assert(is_node_in(root, 55) == TRUE);
    assert(is_node_in(root, 31) == TRUE);
    assert(is_node_in(root, 17) == TRUE);
    assert(is_node_in(root, 15) == TRUE);
    assert(is_node_in(root, -90) == TRUE);
    assert(is_node_in(root, -33) == TRUE);
    assert(is_node_in(root, -27) == TRUE);
    assert(is_node_in(root, 76) == TRUE);
    assert(is_node_in(root, 20) == TRUE);
    
    assert(is_node_in(root, 99) == FALSE);
    assert(is_node_in(root, 87) == FALSE);
    assert(is_node_in(root, -10) == FALSE);
    assert(is_node_in(root, -1) == FALSE);
    assert(is_node_in(root, 54) == FALSE);
    assert(is_node_in(root, -18) == FALSE);
    assert(is_node_in(root, -31) == FALSE);
    assert(is_node_in(root, 98) == FALSE);
    assert(is_node_in(root, 100) == FALSE);
    assert(is_node_in(root, 51) == FALSE);
    assert(is_node_in(root, 41) == FALSE);
    assert(is_node_in(root, 3) == FALSE);
    assert(is_node_in(root, -3) == FALSE);
    assert(is_node_in(root, 77) == FALSE);
    assert(is_node_in(root, -77) == FALSE);
    assert(is_node_in(root, -198) == FALSE);
    assert(is_node_in(root, 101) == FALSE);
    assert(is_node_in(root, 200) == FALSE);
    assert(is_node_in(root, 100000) == FALSE);
    assert(is_node_in(root, -100000) == FALSE);

    assert(node_search(root, -100)->key == -100);
    assert(node_search(root, 34)->key == 34);
    assert(node_search(root, 22)->key == 22);
    assert(node_search(root, -58)->key == -58);
    assert(node_search(root, -4)->key == -4);
    assert(node_search(root, -2)->key == -2);
    assert(node_search(root, 0)->key == 0);
    assert(node_search(root, 67)->key == 67);
    assert(node_search(root, 78)->key == 78);
    assert(node_search(root, 18)->key == 18);
    assert(node_search(root, 19)->key == 19);
    assert(node_search(root, 55)->key == 55);
    assert(node_search(root, 31)->key == 31);
    assert(node_search(root, 17)->key == 17);
    assert(node_search(root, 15)->key == 15);
    assert(node_search(root, -90)->key == -90);
    assert(node_search(root, -33)->key == -33);
    assert(node_search(root, -27)->key == -27);
    assert(node_search(root, 76)->key == 76);
    assert(node_search(root, 20)->key == 20);

    root = create_tree(500);
    int integer_list3[30] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,
                            50, 150, 250, 350, 450, 550, 650, 750, 850, 950,
                            75, 125, 175, 225, 375, 425, 525, 775, 825, 975};
    for (int i = 0; i < 30; i++)
    {
        insert_into_tree(root, integer_list3[i]);
    }

    print_tree_inorder(root);

    assert(is_node_in(root, 100) == TRUE);
    assert(is_node_in(root, 200) == TRUE);
    assert(is_node_in(root, 300) == TRUE);
    assert(is_node_in(root, 400) == TRUE);
    assert(is_node_in(root, 500) == TRUE);
    assert(is_node_in(root, 600) == TRUE);
    assert(is_node_in(root, 700) == TRUE);
    assert(is_node_in(root, 800) == TRUE);
    assert(is_node_in(root, 900) == TRUE);
    assert(is_node_in(root, 1000) == TRUE);
    assert(is_node_in(root, 50) == TRUE);
    assert(is_node_in(root, 150) == TRUE);
    assert(is_node_in(root, 250) == TRUE);
    assert(is_node_in(root, 350) == TRUE);
    assert(is_node_in(root, 450) == TRUE);
    assert(is_node_in(root, 550) == TRUE);
    assert(is_node_in(root, 650) == TRUE);
    assert(is_node_in(root, 750) == TRUE);
    assert(is_node_in(root, 850) == TRUE);
    assert(is_node_in(root, 950) == TRUE);
    assert(is_node_in(root, 75) == TRUE);
    assert(is_node_in(root, 125) == TRUE);
    assert(is_node_in(root, 175) == TRUE);
    assert(is_node_in(root, 225) == TRUE);
    assert(is_node_in(root, 375) == TRUE);
    assert(is_node_in(root, 425) == TRUE);
    assert(is_node_in(root, 525) == TRUE);
    assert(is_node_in(root, 775) == TRUE);
    assert(is_node_in(root, 825) == TRUE);
    assert(is_node_in(root, 975) == TRUE);

    assert(is_node_in(root, 1) == FALSE);
    assert(is_node_in(root, -20) == FALSE);
    assert(is_node_in(root, 101) == FALSE);
    assert(is_node_in(root, -200) == FALSE);
    assert(is_node_in(root, -333) == FALSE);
    assert(is_node_in(root, -901) == FALSE);
    assert(is_node_in(root, -555) == FALSE);
    assert(is_node_in(root, 872) == FALSE);
    assert(is_node_in(root, 894) == FALSE);
    assert(is_node_in(root, 111) == FALSE);
    assert(is_node_in(root, 281) == FALSE);
    assert(is_node_in(root, 7483) == FALSE);
    assert(is_node_in(root, 8461) == FALSE);
    assert(is_node_in(root, 272) == FALSE);
    assert(is_node_in(root, 22) == FALSE);
    assert(is_node_in(root, 776) == FALSE);
    assert(is_node_in(root, 92) == FALSE);
    assert(is_node_in(root, 80) == FALSE);
    assert(is_node_in(root, 17) == FALSE);
    assert(is_node_in(root, -9) == FALSE);
    assert(is_node_in(root, -1) == FALSE);
    assert(is_node_in(root, 104) == FALSE);
    assert(is_node_in(root, 912) == FALSE);
    assert(is_node_in(root, 490) == FALSE);
    assert(is_node_in(root, 677) == FALSE);
    assert(is_node_in(root, 819) == FALSE);
    assert(is_node_in(root, 441) == FALSE);
    assert(is_node_in(root, -8) == FALSE);
    assert(is_node_in(root, -525) == FALSE);
    assert(is_node_in(root, -727) == FALSE);

    assert(node_search(root, 100)->key == 100);
    assert(node_search(root, 200)->key == 200);
    assert(node_search(root, 300)->key == 300);
    assert(node_search(root, 400)->key == 400);
    assert(node_search(root, 500)->key == 500);
    assert(node_search(root, 600)->key == 600);
    assert(node_search(root, 700)->key == 700);
    assert(node_search(root, 800)->key == 800);
    assert(node_search(root, 900)->key == 900);
    assert(node_search(root, 1000)->key == 1000);
    assert(node_search(root, 50)->key == 50);
    assert(node_search(root, 150)->key == 150);
    assert(node_search(root, 250)->key == 250);
    assert(node_search(root, 350)->key == 350);
    assert(node_search(root, 450)->key == 450);
    assert(node_search(root, 550)->key == 550);
    assert(node_search(root, 650)->key == 650);
    assert(node_search(root, 750)->key == 750);
    assert(node_search(root, 850)->key == 850);
    assert(node_search(root, 950)->key == 950);
    assert(node_search(root, 75)->key == 75);
    assert(node_search(root, 125)->key == 125);
    assert(node_search(root, 175)->key == 175);
    assert(node_search(root, 225)->key == 225);
    assert(node_search(root, 375)->key == 375);
    assert(node_search(root, 425)->key == 425);
    assert(node_search(root, 525)->key == 525);
    assert(node_search(root, 775)->key == 775);
    assert(node_search(root, 825)->key == 825);
    assert(node_search(root, 975)->key == 975);

    printf("\nAll search tests are done!\n");
}

void print_tree_preorder(struct node* root){
    if(root != NULL){
        printf("Node Value: %i\n", root->key);
        print_tree_preorder(root->left);
        print_tree_preorder(root->right);
    }
}

void print_tree_inorder(struct node* root) {
    if (root != NULL) {
        print_tree_inorder(root->left);
        printf("Node Value: %i\n", root->key);
        print_tree_inorder(root->right);
    }
}

void print_tree_postorder(struct node* root) {
    if (root != NULL) {
        print_tree_postorder(root->left);
        print_tree_postorder(root->right);
        printf("Node Value: %i\n", root->key);
    }
}

void test_print_trees() {
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree;
            2 - Insert numbers into the created tree (insertion method is the tester's choice);
            3 - Print the tree using print_tree_preorder, print_tree_inorder and print_tree_postorder;
            4 - Compare the results and check (manually) if the results printed are correct
        --------------------------------------------
    */

    struct node* root = create_tree(5); // 1
    // 2
    insert_into_tree(root, 3);
    insert_into_tree(root, 2);
    insert_into_tree(root, 4);
    insert_into_tree(root, 7);
    insert_into_tree(root, 6);
    insert_into_tree(root, 8);
    // 3
    printf("\nPrinting preorder walk\n");
    print_tree_preorder(root);
    printf("\nPrinting inorder walk\n");
    print_tree_inorder(root);
    printf("\nPrinting postorder walk\n");
    print_tree_postorder(root);

    //try with a bigger list
    root = create_tree(50);
    int integer_list[20] = {4, 1, -3, 44, 55, 91, 20, 78, 81, 33, 41, 2, 18, -18, 100, 29, 80, 71, 0, 51};
    int integer_list_size = sizeof integer_list / sizeof integer_list[0];
    for (int i = 0; i < integer_list_size; i++)
    {
        insert_into_tree(root, integer_list[i]);
    }
    printf("\nPrinting preorder walk\n");
    print_tree_preorder(root);
    printf("\nPrinting inorder walk\n");
    print_tree_inorder(root);
    printf("\nPrinting postorder walk\n");
    print_tree_postorder(root);

    printf("\nAll walk tests are done!\n");
}

struct node* maximum_node(struct node* root) {
    if (root->right != NULL) {
        return maximum_node(root->right);
    }
    return root;
}

struct node* minimum_node(struct node* root) {
    if (root->left != NULL) {
        return minimum_node(root->left);
    }
    return root;
}

void test_maximum_node() {
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree;
            2 - Add as many nodes in the tree as you want (method of insertion is up to the tester)
            3 - Use maximum_node on the created tree (passing the root);
            4 - And then check if the returned node is the correct one (method of verification is up to the tester).
        --------------------------------------------
    */

    struct node* root = create_tree(5); // 1
    // 2
    insert_into_tree(root, 6);
    insert_into_tree(root, 7);
    insert_into_tree(root, 8);
    insert_into_tree(root, 2);
    insert_into_tree(root, 1);
    insert_into_tree(root, 3); 
    insert_into_tree(root, 4);

    struct node* max_node = maximum_node(root);

    assert(max_node->key == 8);

    root = create_tree(20);

    insert_into_tree(root, 6);
    insert_into_tree(root, 7);
    insert_into_tree(root, 8);
    insert_into_tree(root, 2);
    insert_into_tree(root, 1);
    insert_into_tree(root, 3);
    insert_into_tree(root, 4);
    insert_into_tree(root, -1);
    insert_into_tree(root, 0);
    insert_into_tree(root, 82);
    insert_into_tree(root, -10);
    insert_into_tree(root, 90);
    insert_into_tree(root, 71);
    insert_into_tree(root, 15);

    max_node = maximum_node(root);
    assert(max_node->key == 90);

    printf("\nAll maximum node tests are done!\n");
}

void test_minimum_node() {
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree;
            2 - Add as many nodes in the tree as you want (method of insertion is up to the tester)
            3 - Use minimum_node on the created tree (passing the root);
            4 - And then check if the returned node is the correct one (method of verification is up to the tester).
        --------------------------------------------
    */

    struct node* root = create_tree(5); // 1
    // 2
    insert_into_tree(root, 6);
    insert_into_tree(root, 7);
    insert_into_tree(root, 8);
    insert_into_tree(root, 2);
    insert_into_tree(root, 1);
    insert_into_tree(root, 3);
    insert_into_tree(root, 4);

    struct node* min_node = minimum_node(root); // 3

    assert(min_node->key == 1); // 4

    root = create_tree(20);

    insert_into_tree(root, 6);
    insert_into_tree(root, 7);
    insert_into_tree(root, 8);
    insert_into_tree(root, 2);
    insert_into_tree(root, 1);
    insert_into_tree(root, 3);
    insert_into_tree(root, 4);
    insert_into_tree(root, -1);
    insert_into_tree(root, 0);
    insert_into_tree(root, 82);
    insert_into_tree(root, -10);
    insert_into_tree(root, 90);
    insert_into_tree(root, 71);
    insert_into_tree(root, 15);

    min_node = minimum_node(root);
    assert(min_node->key == -10);

    printf("\nAll minimum node tests are done!\n");
}

// This is a hard algorithm for me to understand...
// There are three cases for the algorithm:
//      First case: The node for deletion has no children (we just set the parent's atribute (parent->right or parent->left) to NULL);
//      Second case: The node for deletion has one child (we have to link this one child with the parent of the node that was deleted);
//      Third case: The node for deletion has two children (we have to get the successor node and switch position with the deleted node, 
//                  and delete the successor).
struct node* delete_from_tree(struct node* root, int key_value){
    if(root == NULL){
        return root;
    }
    //Searching for the node to delete
    if(key_value < root->key){
        root->left = delete_from_tree(root->left, key_value);
    }else if(key_value > root->key){
        root->right = delete_from_tree(root->right, key_value);
    }else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minimum_node(root->right);
        root->key = temp->key;
        root->right = delete_from_tree(root->right, temp->key);
    }
    return root;
}

void test_delete_from_tree(){
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree;
            2 - Insert as many nodes as you want (method of insertion is up to the tester);
            3 - Delete a node with no child, a node with one child and then one node with 2 children;
            4 - Print the tree inorder.
        --------------------------------------------
    */

    struct node* root = create_tree(10); // 1
    
    // 2
    insert_into_tree(root, 15);
    insert_into_tree(root, 9);
    insert_into_tree(root, 2);
    insert_into_tree(root, 22);
    insert_into_tree(root, -3);
    insert_into_tree(root, -7);
    insert_into_tree(root, 3);
    insert_into_tree(root, 0);
    insert_into_tree(root, 17);
    insert_into_tree(root, 11);


    // 3
    printf("\nPrinting tree inorder...\n");
    struct node* new_root0 = delete_from_tree(root, 17);
    assert(new_root0->key == 10);
    print_tree_inorder(root); // 4

    printf("\nPrinting tree inorder...\n");
    struct node* new_root1 = delete_from_tree(root, 9);
    assert(new_root1->key == 10);
    print_tree_inorder(root); // 4

    printf("\nPrinting tree inorder...\n");
    struct node* new_root2 = delete_from_tree(root, 10);
    assert(new_root2->key == 11);
    print_tree_inorder(root); // 4
    
    root = create_tree(50);

    insert_into_tree(root, 80);
    insert_into_tree(root, 90);
    insert_into_tree(root, 40);
    insert_into_tree(root, 55);
    insert_into_tree(root, 33);
    insert_into_tree(root, 88);
    insert_into_tree(root, 64);
    insert_into_tree(root, 21);
    insert_into_tree(root, 10);
    insert_into_tree(root, 19);
    insert_into_tree(root, 39);
    insert_into_tree(root, 78);
    insert_into_tree(root, 95);
    insert_into_tree(root, 52);
    insert_into_tree(root, 67);
    insert_into_tree(root, 49);
    insert_into_tree(root, 37);

    printf("\nPrinting tree inorder...\n");
    new_root0 = delete_from_tree(root, 67);
    assert(new_root0->key == 50);
    print_tree_inorder(root);

    printf("\nPrinting tree inorder...\n");
    new_root1 = delete_from_tree(root, 21);
    assert(new_root1->key == 50);
    print_tree_inorder(root);

    printf("\nPrinting tree inorder...\n");
    new_root2 = delete_from_tree(root, 80);
    assert(new_root2->key == 50);
    print_tree_inorder(root);

    printf("\nAll deletion tests are done!\n");    
}

struct node* free_tree(struct node* root){
    if(root == NULL){
        return root;
    }
    root->right = free_tree(root->right);
    root->left = free_tree(root->left);
    root = NULL;
    return root;
}

void test_free_tree(){
    /*
        ---------------TEST STRUCTURE---------------
            1 - Create a tree;
            2 - Insert as many nodes as you want (method of insertion is up to the tester);
            3 - Use free_tree() on the root of the tree.
        --------------------------------------------
    */

    // 1
    struct node* root = create_tree(50);

    // 2
    insert_into_tree(root, 80);
    insert_into_tree(root, 90);
    insert_into_tree(root, 40);
    insert_into_tree(root, 55);
    insert_into_tree(root, 33);
    insert_into_tree(root, 88);
    insert_into_tree(root, 64);
    insert_into_tree(root, 21);
    insert_into_tree(root, 10);
    insert_into_tree(root, 19);
    insert_into_tree(root, 39);
    insert_into_tree(root, 78);
    insert_into_tree(root, 95);
    insert_into_tree(root, 52);
    insert_into_tree(root, 67);
    insert_into_tree(root, 49);
    insert_into_tree(root, 37);

    // 3
    root = free_tree(root);
    assert(root == NULL);

    printf("\nAll tree freeing tests are done!\n");
}

int main(void){
    test_insert_into_tree();
    test_node_search();
    test_print_trees();
    test_maximum_node();
    test_minimum_node();
    test_delete_from_tree();
    test_free_tree();
}
