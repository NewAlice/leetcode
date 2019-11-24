Void printListReversing_iteratively(ListNode* pHead)
{
    Std::stack<ListNode*> nodes;
    
     ListNode* pNode = PHead;
     While( pNode != NULL){
          Nodes.push(pNode);
          pNode = pNode->next;

     }
     while(!nodes.empty()){
         pNode = nodes.top();
	printf(“%s\t”, pNode->value);
         nodes.pop();
    }
}


void printReversingly_recusively(LIstNode* pHead){
	if (pHead != NULL){
                If (pHead->next != NULL){
                		printReversingly_recusively((pHead->next );
                }
		printf(“%s\t”, pNode->value)
        }
}
