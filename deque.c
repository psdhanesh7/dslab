#include<stdio.h>
int ar[100],size,front,rear;
void  pop()
{      
        int value;
        if(rear==-1)
        {
                printf("Underflow\n");
        }
        else if(front==rear)
        {
        value=ar[rear];
        front=rear=-1;
        }
        else
        {
                value=ar[rear];
                rear--;
        }

}
void enqueue(int value)
{
        if(front==-1)
        {
                front=rear=0;
                ar[rear]=value;
        }
        else if(rear<size-1)
        {
                rear=rear+1;
                ar[rear]=value;
        }
        else
                printf("Overflow\n");
}
void insert(int value)
{
        if(front==0|| front==-1)
                printf("Insertion not possible\n");
        else
        {
                front--;
                ar[front]=value;
        }

}
void dequeue()
{
        int value;
        if(front==-1)
                printf("Underflow\n");
        else if(front==rear)
        {
                value=ar[rear];
                front=rear=-1;
        }
        else
                value=ar[front++];
}
void display()
{
        int i;
        if(front==-1)
                printf("Queue Empty\n");
        else
        {
                printf("Front-->\t");
                for(i=front;i<=rear;i++)
                        printf("%d\t",ar[i]);
                printf("<--Rear\n");
        }
}

void main()
{
        int choice,value;
        printf("Enter the size of the Queue:");
        scanf("%d",&size);
        do
        {
                label:
                front=rear=-1;
                printf("____MENU____\n1.Input restricted Queue\n2.Output restricted queue\n3.Exit\n");
                printf("Enter your chice:");
                scanf("%d",&choice);
                if(choice==3)
                        goto end;
                do
                {
                        if(choice==1)
                        {
                                int ch;
                                printf("\n___Operations___\n1.Insertion(At rear)\n2.Deletion (At front)\n3.Deletion (At rear)\n4.Display\n5.Exit\n");
                                printf("Enter your choice:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                        case 1: printf("Enter the element to be inserted:");
                                                scanf("%d",&value);
                                                enqueue(value);
                                                break;
                                        case 2: dequeue();
                                                break;
                                        case 3: pop();
                                                break;
                                        case 4: printf("Current status of Deque is :\n");
                                                display();
                                                break;
                                        case 5: goto label;
                                                break;
                                        default: printf("Invalid choice!!!\n");
                                        }

                                }
                        else if(choice==2)
                        {
                                int ch;
                                printf("\n___Operations___\n1.Insertion(At front)\n2.Insertion (At rear)\n3.Deletion (At front)\n4.Display\n5.Exit\n");
                                printf("Enter your choice:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                        case 1: printf("Enter the element to be inserted:");
                                                scanf("%d",&value);
                                                insert(value);
                                                break;
                                        case 2: printf("Enter the element to be inserted:");
                                                scanf("%d",&value);
                                                enqueue(value);
                                                break;
                                        case 3: dequeue();
                                                break;
                                        case 4: printf("Current status of Deque is :\n");
                                                display();
                                                break;
                                        case 5: goto label;

                                        default: printf("Invalid choice!!!\n");
                                }
                        }
                        else
                                printf("Invalid Choice!!!\n");
                }while(1);

        }while(1);
        end:;
}