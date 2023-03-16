//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTreeUtil(int in[], int post[], int si, int ei, int &pIndex){
        if(si > ei) // s: starting Index, e: ending Index
            return NULL;
        int curr = post[pIndex]; // current ele in postorder
        Node *temp = new Node(curr);
        pIndex--;

        // if(si == ei) return temp; // if node has no children

        int inIndex;
        for(int i = si; i <= ei; i++){
            if(in[i] == curr){
                inIndex = i;
                break;
            }
        }
        // int inIndex = mp[curr]; // index of curr in inorder

        temp->right = buildTreeUtil(in, post, inIndex+1, ei, pIndex);
        temp->left = buildTreeUtil(in, post, si, inIndex-1, pIndex);

        return temp;
    }

Node *buildTree(int in[], int post[], int n) {
    // Your code here
        // unordered_map<int, int> mp;
        // for (int i = 0; i < n; i++)
        //     mp[inorder[i]] = i;
 
        int index = n - 1; // Index in postorder
        return buildTreeUtil(in, post, 0, n - 1, index);
}
