#include<iostream>
using namespace std;
#include<conio.h> 
#include<stdio.h>
class Node 
{  public:   double data; // data  
   Node* next; // pointer to next 

}; 
 
class List 
{  public:   
List(void) 
{ head = NULL; } // constructor   
~List(void); // destructor   
bool IsEmpty() 
{ return head == NULL; }
   
Node* InsertNode(int index, double x);
   int FindNode(double x);   
   int DeleteNode(double x);  
    void DisplayList(void);  
	private:   Node* head;
	 }; 
 
Node* List::InsertNode(int index, double x)
  {  
  if (index < 0) return NULL; 
    int currIndex = 1;  
	Node* currNode = head;
	  while (currNode && index > currIndex)  
	   {   //Try to locate index'th node. If it doesn't exist, return NULL   
	   currNode = currNode->next;     currIndex++;  
	   }   
	    if (index > 0 && currNode == NULL)
		{
		  return NULL;
		  }
		      Node* newNode = new Node;  
			   newNode->data = x;  
 if (index == 0)  
 {    newNode->next = head;    head = newNode;  
 
 } 
 
  else  
   {   
   newNode->next = currNode->next;    currNode->next = newNode;
   
     }     return newNode;  
	 
	 } 
 
int List::FindNode(double x)
 {   Node* currNode = head;   
 int currIndex = 1;   
 while (currNode && currNode->data != x)
   {   
    currNode = currNode->next;   
	 currIndex++;   } 
	    if (currNode) 
		return currIndex;     
		return 0; } 
 
int List::DeleteNode(double x)
 {
   Node* prevNode = NULL; 
    Node* currNode = head;
	  int currIndex = 1; 
	   while (currNode && currNode->data != x)
	     {  
		  prevNode = currNode;   currNode = currNode->next;   currIndex++;
		    } 
   if (currNode) 
    {  
	 if (prevNode) 
	   {   
	    prevNode->next = currNode->next; 
		   delete currNode;  
		    }  
			 else 
			   {    
			   head = currNode->next;   
			    delete currNode;  
				 }      
				 return currIndex;
				   }   
				    return 0; 
					} 
 
void List::DisplayList()
 {
 	cout<<"\n\n\n displaying list you entered :)\n\n";
   int num = 0; 
    Node* currNode = head; 
	 while (currNode != NULL) 
	  {   cout << currNode->data << endl;
	     currNode = currNode->next;  
		  num++; 
		   } 
		   
		    cout << "\n\n Number of nodes in the list:	 \n" << num << endl; } 
 
List::~List(void) 
{ 
 Node* currNode = head;
   Node* nextNode = NULL;
     while (currNode != NULL)
	   {  
	    nextNode = currNode->next; 
  delete currNode; // destroy the current node  
   currNode = nextNode; 
    }
	 } 
 
main()
 {
   List list;
   	int index;//variable for index
double data;// variable for data
int z;// variable for iteration 
cout<<"How many Enteries you want to have in your list :)\n ";
cin>>z;
for(int i=0;i<z;i++)
{
	cout<<"Enter Data :) "<<endl;//(data you want to enter your list)
cin>>data;
index=i;
 list.InsertNode(index, data); // successful 
}//for

		   // display list  
		   list.DisplayList(); 
		   char ch;
		   cout<<"\n\n do you want to find node pr delete one? \n\n 1-Yes(Y)-*Delete(D). \n 2-Yes(Y)-*FindNode. \n3-No(N)\n";
		//menu forperforming actions
		again:
		
		   	cout<<"\nEnter your Choice (1-3)";
		   	cin>>ch;
		   	int q;//data variable
		   switch(ch)
   			{
				case '1':
					cout<<"Enter Data you want to Dlete :\n";
					cin>>q;
					list.DeleteNode(q);
					list.DisplayList(); 
					goto again;	
					break;
				case '2':
					cout<<"Enter Data you want to Find Node of :\n";
					cin>>q;
					if(list.FindNode(q) > 0)   
					{
			  			cout <<q<<" found" << endl; 
			 		 }
			  
			   		else  
			   		{
			    		cout <<q<<"not found" << endl; 
						}
					list.DisplayList(); 
					goto again;	
					break;
					
				case '3':
					cout<<"HAVE A GUD DAY :) ";
					break;
					
				default:
				    cout<<"you have entered invalid choice :( ";
					goto again;	
					
				
			}//switch
				
					   return 0; 
					   }//main
