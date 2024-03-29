struct Node* reverse(Node* head){
       
         struct Node* curr=head;
         struct Node* prev=NULL;
         struct Node* forward=NULL;
       
       while(curr!=NULL){
           forward=curr->next;
           curr->next=prev;
           prev=curr;
           curr=forward;
       }
       
       return prev;
}






void  insertTail(struct Node* &tail , int data){
   
   struct Node* temp = new Node(data);
   
   tail->next = temp;
   tail = temp;
   
}




   
   
struct Node* addTwoLList(struct Node* head1 , struct Node* head2)
   {
       
       if(head1 == NULL){
           return head2;
       }
       
       else if(head2 == NULL){
           return head1;
       }
       
       else{
           
           struct Node* head= new Node(-1);
           struct Node* tail = head;
           
           
           int carry = 0;
       
               while(head1 != NULL && head2 != NULL){
                    
                    int sum = head1->data +  head2->data + carry;
                    
                    int ans = sum %10;
                    carry = sum /10;
                    
                    insertTail(tail , ans);
                    
                    head1 = head1->next;
                    head2 = head2->next;
                    
               }
               
               
               
               while(head1 != NULL){
                    
                    int sum = head1->data + carry;
                    
                    int ans = sum %10;
                    carry = sum /10;
                    
                    insertTail(tail , ans);
                    
                    head1 = head1->next;
               }
               
               
               while(head2 != NULL){
                    
                    int sum = head2->data + carry;
                    
                    int ans = sum %10;
                    carry = sum /10;
                    
                    insertTail(tail , ans);
                    
                    head2 = head2->next;
               }
               
               
               
               
               if(carry > 0){
                    insertTail(tail , carry);
               }
               
               
           return head->next;
           
          }  // else closing …
  
}   // func closing ….

   
   


 struct Node* addTwoLists(struct Node* first, struct Node* second)
   {
       struct Node* head1 = reverse(first);
       struct Node* head2 = reverse(second);
       
       struct Node *final = addTwoLList(head1 , head2);
       
       final = reverse(final);
       
       return final;



      // Time Comp : O( m+n );

      // Space comp : O( Max(m,n) );
       


   }
   