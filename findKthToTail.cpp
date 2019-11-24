ListNode* FindKthToTail(ListNode* pHead, usigned int k)
{
    if (pListNode == Null)
        return Null;
    
    ListNode *PAhead = PHead;
    ListNode *PBehind = Null;
    
    for (unsigned int i = 0; i< k-1; ++i)
    {
        pAhead = PAhead-> next;
    }
    
    pBehind = PAhead;
    
    while (pAhead->next != Null)
    {
        PAhead = PAhead->next;
        PBehind = pBehind-next;
        
    }
    return PBehind;
    
}
