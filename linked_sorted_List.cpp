void MergeLists(SortedType list1, SortedType list2, SortedType& result) 
{ 
    ItemType item1, item2; 
    list1.ResetList(); 
    while (list1.GetNextItem(item1)) 
        result.PutItem(item1); 
    list2.ResetList(); 
    while (list2.GetNextItem(item2)) 
        result.PutItem(item2); 
} 