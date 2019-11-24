Struct Node {
    int data;
    Struct *pre;
    Struct *pnext;
};



/*push a node to the head of a list*/
void push(struct Node** head, int new_data)
{
    struct Node* new_node (struct Node*)malloc(sizeof(struct Node));
    
    /*put in the data*/
    new_node->data = new_data;
    
    new_node->pnext = (*head_ref);
    new_node->pre = Null;
    
    if((*head_ref) != NULL)
    (*head_ref)->prev = new_node;
    
    (*head_ref) = new_node;
    
}
