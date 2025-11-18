//
// Created by disha on 17-11-2025.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trie{
struct trie *child[256]; // child pointers for all ASCII characters
int eos; // end of string flag
};
struct stack{ // Used to store the path while traversing so we can delete backwards
 struct trie *node;
 int index;
};
typedef struct stack Stack;

char output[30]; // to store current word during traversal
int len=0,top=-1; // len is current length of word, top is stack top index
Stack* STACK[30]; // stack to store trie nodes and their indices for deletion

typedef struct trie Trie;

// PUSH
void push(Trie *t,int index){
    Stack *nn=(Stack*)malloc(sizeof(Stack));
    nn->node=t;
    nn->index=index;
    STACK[++top]=nn;
}

// POP
Stack* pop()
{
    return STACK[top--];
}

// Count children
int ChildCount(Trie *t)
{
    int count=0;
    for(int i=0;i<256;i++)
        if(t->child[i]!=NULL)
            count++;
    return count;
}

// Create Node
Trie* createNode()
{
    Trie *nn=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<256;i++)
        nn->child[i]=NULL;     // FIXED BUG
    nn->eos=0;
    return nn;
}

// INSERT
void insertWord(char *word,Trie *root)
{
    int index;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++)
    {
        index=word[i];
        if(t->child[index]==NULL)
            t->child[index]=createNode();
        t=t->child[index];
    }
    t->eos=1;
}

// DISPLAY all words
void display(Trie *root){
    Trie *t=root;
    for(int i=0;i<256;i++)
    {
        if(t->child[i]!=NULL)
        {
            output[len++]=i;
            if(t->child[i]->eos==1)
            {
                printf("\n");
                for(int j=0;j<len;j++)
                    printf("%c",output[j]);
            }
            display(t->child[i]);
            len--;         // FIXED PLACE
        }
    }
}

// SEARCH
void search(char *word,Trie *root){
    int index;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++){
      index=word[i];
      if(t->child[index]==NULL){
          printf("\nData not found");
          return;
      }
      t=t->child[index];
    }
    printf(t->eos ? "\nData found" : "\nData not found");
}

// DELETE
void deleteData(char *word,Trie *root){
    int index;
    Stack *s;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++){
      index=word[i];
      if(t->child[index]==NULL){
          printf("\nData not found");
          return;
      }
      push(t,index);
      t=t->child[index];
    }

    t->eos=0;

    if(ChildCount(t)>=1) return;

    while(top>=0){
        s=pop();
        Trie *parent=s->node;
        index=s->index;

        free(parent->child[index]);
        parent->child[index]=NULL;

        if(parent->eos==1 || ChildCount(parent)>=1)
            break;
    }
}

//////////////////////////////////////////////////////////////////
//   ⭐⭐  NEW UPGRADE FUNCTIONS (NO ORIGINAL FUNCTIONS REMOVED) ⭐⭐
//////////////////////////////////////////////////////////////////

// DISPLAY WORDS OF GIVEN LENGTH
void displayLength(Trie *root, int reqLen){
    if(root==NULL) return;

    for(int i=0;i<256;i++){
        if(root->child[i]!=NULL){
            output[len++]=i;

            if(root->child[i]->eos==1 && len==reqLen){
                printf("\n");
                for(int j=0;j<len;j++) printf("%c",output[j]);
            }

            displayLength(root->child[i], reqLen);
            len--;
        }
    }
}

// DISPLAY WORDS WITH PREFIX
void displayPrefix(Trie *root, char *prefix){
    Trie *t=root;

    for(int i=0;prefix[i]!='\0';i++){
        int idx=prefix[i];
        if(t->child[idx]==NULL){
            printf("\n❌ No word with this prefix");
            return;
        }
        output[len++]=idx;
        t=t->child[idx];
    }

    printf("\n➡ Words starting with \"%s\":",prefix);
    display(t);
    len=0;
}

//////////////////////////////////////////////////////////////////
// MODIFIED MENU (ONLY ADDED OPTIONS)
//////////////////////////////////////////////////////////////////

void main()
{
    Trie *root;
    int ch,lenReq;
    char word[30],prefix[30];

    root=createNode();

    do{
    printf("\n\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Display same length\n6.Display prefix\n7.Exit\nEnter choice:");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        printf("Enter word:");
        scanf("%s",word);
        insertWord(word,root);
        break;

    case 2:
        len=0;
        printf("\nAll words:");
        display(root);
        break;

    case 3:
        printf("Enter word to search:");
        scanf("%s",word);
        search(word,root);
        break;

    case 4:
        printf("Enter word to delete:");
        scanf("%s",word);
        deleteData(word,root);
        break;

    case 5:
        printf("Length?");
        scanf("%d",&lenReq);
        len=0;
        displayLength(root,lenReq);
        break;

    case 6:
        printf("Enter prefix:");
        scanf("%s",prefix);
        len=0;
        displayPrefix(root,prefix);
        break;

    default:
        return;
    }

    }while(ch);
}
