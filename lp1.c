/*
	Using circular representation for a polynomial design ,develope and execute a program in C to accept two polynomials , add them 
	and pint the esulting value.

*/
#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,n,type)\
	p=(type*) malloc(n*sizeof(int));
	
#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)	
struct node {
	int coeff,expo;
	struct node *link;
};

typedef struct node* NODE;
void display(NODE head)
{
	NODE temp;
	if(head->link==head)
	{
		printf("polynomial doesnt exsist\n");
		return;
		}
	temp=head->link;
	while(temp!=head)
	{
		if(temp->coeff<0)
			printf("%2dx^%2d",temp->coeff,temp->expo);
		else
			printf("+%2dx^%2d",temp->coeff,temp->expo);
		temp=temp->link;
	}
}
NODE attach(int coeff,int expo,NODE head)
{
	NODE cur,temp;
	MALLOC(temp,1,struct node);
	temp->coeff=coeff;
	temp->expo=expo;
	cur=head->link;
	while(cur->link!=head)
		cur=cur->link;
	cur->link=temp;
	temp->link=head;
	return head;
	
}
NODE readpoly(NODE head)
{
	int i=1,coeff,expo;
	printf("enter coeff as -999 to end the polynomial:");
	while(1)
	{
		printf("\nenter %d term\n",i++);
		printf("coeff:");
		scanf("%d",&coeff);
		if(coeff==-999)
			break;
		printf("power of x:");
		scanf("%d",&expo);
		head=attach(coeff,expo,head);
		}
	return head;
	}
NODE polyadd(NODE head1,NODE head2,NODE head3)			
{	
	NODE a,b;
	int coeff;
	a=head1->link;
	b=head2->link;
	while(a!=head1 && b!=head2)
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case 0:coeff=a->coeff+b->coeff;
					if(coeff!=0)
						head3=attach(coeff,a->exp,head3);
					a=a->link;
					b=b->link;
					break;
			case 1:head3=attach(a->coeff,a->exp,head3);
					a=a->link;
					break;
			default:head3=attach(b->coeff,b->exp,head3);
					b=b->link;
			}
		}
	while(a!=head1)
	{
		head3=attach(a->coeff,a->exp,head3);
		a=a->link;
		}
	while(b!=head2)
	{
		head3=attach(b->coeff,b->exp,head3);
		b=b->link;							
	}
	return head3;
	}
	
int main()
{
	NODE head1,head2,head3;
	MALLOC(head1,1,struct node);
	MALLOC(head2,1,struct node);
	MALLOC(head3,1,struct node);	
	head1->link=head1;
	head2->link=head2;				
	head3->link=head3;			
	printf("Enter first poly:");
	head1=readpoly(head1);
	printf("Enter 2nd poly:");
	head2=readpoly(head2);				
	
	
	head3=polyadd(head1,head2,head3);
	printf("poly 1 :");	
	display(head1);			
	printf("\npoly 2 :");	
	display(head2);					
	printf("\npoly 3 :");	
	display(head3);
	return;
	}					
					
	/*
		Author - Melrick
			*/				
					
					
					
					
					
			
									
			
			
			
			
			
			
			
			
			
			








		
	
	
	
	
	
					
