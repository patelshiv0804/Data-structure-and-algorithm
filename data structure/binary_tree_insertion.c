struct node
{   int data;
    struct node *right;
    struct node *left; };

struct node* createnode(int data){
    struct node* n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

void insert(struct node *root, int key)
{ struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;  }
        else if (key > root->data)
        {
            root = root->right;  }
        else
        {
            root = root->left;  }
    }
    struct node *new = createnode(key);
    if (key > prev->data)
    {
        prev->right = new;
    }
    else
    {  prev->left = new;
    }
}

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(6);
    struct node *p2 = createnode(3);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    struct node *p5 = createnode(7);

    p->left = p2;
    p->right = p1;
    p1->right = p5;
    p2->right = p4;
    p2->left = p3;

    insert(p, 2);
    return 0;
}