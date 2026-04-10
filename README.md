# playlist-manager-doubly-linked-list
                                 **** Algorithms:****
1)Add Song
    1. Start  
    2. Input song name  
    3. Create a new node  
    4. If playlist is empty:
      Set head = tail = current = new node  
    5. Else:
           Link new node at end  
               Update tail  
    6. End

    
2)Display Playlist
    1. Start  
    2. Set temp = head  
    3. If temp == NULL:
      Print "Playlist is empty"  
    4. Else:
      While temp != NULL:
           Print song title  
           Move temp to next  
    5. End  

    
3)Play Current Song
    1. Start  
    2. Set temp = head  
    3. If temp == NULL:
      Print "Playlist is empty"  
    4. Else:
      While temp != NULL:
           Print song title  
           Move temp to next  
    5. End  

4)Next Song
    1. Start  
    2. If current != NULL AND current->next != NULL:
      Move current to next node  
      Play current song  
    3. Else:
      Print "No next song"  
    4. End  

5)Previous Song
    1. Start  
    2. If current != NULL AND current->prev != NULL:
      Move current to previous node  
      Play current song  
    3. Else:
      Print "No previous song"  
    4. End  
    

6)Delete Song
    1. Start  
2. Input song name  
3. Set temp = head  
4. Traverse list:
      If song found:
          If only one node:
               head = tail = current = NULL  
          Else if deleting head:
               Move head to next  
               Set head->prev = NULL  
          Else if deleting tail:
               Move tail to previous  
               Set tail->next = NULL  
          Else:
               Link previous and next nodes  
          If current == temp:
               Move current to next or previous  
          Delete node  
          Print "Song deleted"  
          Stop  
    5. If not found:
      Print "Song not found"  
    6. End  



<img width="1024" height="1536" alt="Playlist manager flowchart in C++" src="https://github.com/user-attachments/assets/39fac0f9-fd43-4c7a-a81d-13e957dc71ad" />






