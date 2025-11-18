//
// Created by disha on 17-11-2025.
//

// Implement of Trie data structure or implementation of dictionary using trie Ds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> // During crawling, we need to check if the current node is the last node of the word

#define ALPHABET 26                     // Only lowercase a-z supported (26 letters)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])    // Calculate number of elements in an array
#define CHAR_INDEX(c) ((int)c - (int)'a')       // Convert character 'c' to index 0-25

// Trie Data structure
struct node {
    struct node* children[ALPHABET];  // Array of 26 pointers for child nodes (one per letter)
    bool EOW;                         // Boolean flag: is this node the End Of a Word?
};

// Create a new node
struct node *new_node(void)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp) // Check if malloc succeeded
    {
        temp->EOW=false;
        for(int i=0;i<ALPHABET;i++)
        {
            temp->children[i]=NULL;
        }
    }
    return temp;
}
// insert a word in the trie
void insert(struct node *root, const char *key)
{
    int length=strlen(key), index;
    struct node *crawl=root;
    for(int level=0;level<length;level++)
    {
        index=CHAR_INDEX(key[level]);
        if(!crawl->children[index])
        crawl->children[index]=new_node();
        crawl=crawl->children[index];
    }
    crawl->EOW=true;
}

// search for a key into the trie
bool search(struct node *root, const char *key)
{
    int length=strlen(key), index;
    struct node *crawl=root;
    for(int level=0;level<length;level++)
    {
        index=CHAR_INDEX(key[level]);
        if(!crawl->children[index])
        return false;
        crawl=crawl->children[index];
}
return (crawl&&crawl->EOW);
}
// a helper function to check if a node has any children
bool has_childdren(struct node *curr)
{
    for(int i=0;i<ALPHABET;i++)
    {
        if(curr->children[i])
        return true;
    }
    return false;
}
// delete a key from the trie
bool delete_key(struct node *root, const char *key, int depth)
{
    if(!root)
    return false;
    // if the end of the key is reached
    if(depth==strlen(key))
    {
        if(root->EOW)
        root->EOW=false;
        //if the node has no children, it cnan be deleted
        if(has_childdren(root))
        {
            free(root);
            return true;
        }
    return false;
    }

int index=CHAR_INDEX(key[depth]);
if(delete_key(root->children[index], key, depth+1))
{
    // unlink the child node
    root->children[index]=NULL;
    //check if the current node can be deleted
    return !root->EOW && !has_childdren(root);
}

return false;
}

int main()
{
    char keys[][8]={"the", "a", "there", "answer", "any", "by", "bye", "their"};
    char output[][32]={"Not present in trie", "Present in trie"};
    struct node *root=new_node();
    // insert keys into the trie
    for(int i=0;i<ARRAY_SIZE(keys);i++)
    {
        insert(root, keys[i]);
    }
    //search for some keys
    printf("%s----%s\n", "the", output[search(root, "the")]);
    printf("%s----%s\n", "these", output[search(root, "these")]);
    //delete a key
    delete_key(root, "the", 0);
    printf("%s----%s\n", "the", output[search(root, "the")]);
    return 0;
}