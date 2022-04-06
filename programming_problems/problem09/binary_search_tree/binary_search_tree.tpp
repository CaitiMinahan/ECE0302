#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    //start initially with curr = root and parent = 0
    Node<KeyType, ItemType>* curr = new Node<KeyType, ItemType>; 
    curr = root; 

    //1) create a node with the provided key and containing the new item 
    Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
    //have the key-value pair point to the insert() method parameters:
    newNode->data = item; 
    newNode->key = key;  
    //initialize parent node as 0: 
    Node<KeyType, ItemType>* parent = new Node<KeyType, ItemType>;
    parent = nullptr; 

    //2) check for an empty tree 
    if(root==nullptr){
        //if empty, insert the new node as the root of the tree:
        root = newNode; 
        newNode = nullptr; //since root is reassigned 
        curr = nullptr; //since root is reassigned 
        delete curr; 
        delete newNode; 
        delete parent; 

        return true; //successfully inserted at the node 
    }

    //3) if not empty, search for the correct insert position utilizing the provided search method
    //and insert the new node 
    // if(!isEmpty()){
        //search if the key already exists (must insert at a unique key):
        search(key, curr, parent); //call search method with curr = root and parent = 0
        parent = nullptr; 

        //condition for finding a matching key (means we cannot insert):
        if(curr->data!=item){
            //if key < last visited 
            if(key<curr->key){
                //insert left child 
                curr->left = newNode; 
            }
            //if key > last visited 
            //insert right child
            else curr ->right = newNode; 

            //deallocate: 
            newNode = nullptr; 
            curr = nullptr; 
            delete curr; 
            delete newNode; 
            delete parent; 

            return true; //successful insert 
        }
        //otherwise, if we have found the matching key, we return false and cannot insert: 
        newNode = nullptr; 
        curr = nullptr; 
        delete curr; 
        delete newNode; 
        delete parent; 

        return false; 
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    //1) create a node with the provided key containing the new item: 
    //start initially with curr = root and parent = 0
    Node<KeyType, ItemType>* curr = new Node<KeyType, ItemType>; 
    curr = root; 

    //initialize parent node as 0: 
    Node<KeyType, ItemType>* parent = new Node<KeyType, ItemType>;
    parent = nullptr;

    //search if the key already exists (must insert at a unique key):
    search(key, curr, parent); //call search method with curr = root and parent = 0
 
    //2) if not empty, search for the key using the provided search method: 
    //if(!isEmpty()){
        //condition for finding a matching key (means we cannot insert):
        if(curr->key!=key){
            //deallocate: 
            curr = nullptr; 
            parent = nullptr;
            delete curr; 
            delete parent; 

            return false; 
        }
    //3) if the key is found, consider the cases below and determine how to node and maintain tree structure:
        // case 1: one thing in the tree (nothing to the left or right and key is located at the root)
        if(root->left==nullptr && root->right==nullptr && key==root->key){
            //then we can just simply delete it: 
            root = nullptr; 
            curr = nullptr; 
            parent = nullptr; 
            delete curr; 
            delete parent; 

           return true; //successful remove
        }
        // case 2: found deleted item at leaf (parent is not nullptr but curr is the deleted item)
        if(parent!=nullptr && curr->left==nullptr && curr->right==nullptr){
            //test which side the deleted leaf is located (right or left?):
           if(parent->left == curr){
                //then delete the left leaf
                parent->left = nullptr; 
              }
             //else delete the right leaf 
            else parent->right = nullptr; 

            //after setting them to null, we must delete the nodes: 
            delete curr; 
            parent = nullptr; 
            delete parent; 

            return true; //successful remove
       }
        // case 3: item to delete has only a right child
        if(curr->left==nullptr && curr->right!=nullptr){
            //need to reassign nodes to make everything leftmost
           if(curr == root){
                root = curr->right; //reassign the root 
            }
            else if(parent->left == curr){
                parent->left = curr->right; //reassign to make curr leftmost in the subtree
            }
            else parent->right = curr->right; 
            
            parent = nullptr; 
            delete curr; 
            delete parent; 
                
            return true; //successful remove
        }
        // case 4: item to delete has only a left child
        if(curr->right==nullptr && curr->left!=nullptr){
            //need to reassign nodes to make everything leftmost
            if(curr == root){
                root = curr->left; //reassign the root 
            }
            else if(parent->left == curr){
                parent->left = curr->left; //reassign to make curr leftmost in the subtree
            }
            else parent->right = curr->left; 

            parent = nullptr; 
            delete curr; 
            delete parent; 
                
            return true; //successful remove
        }
        // case 5: item to delete has two children
        //we need to use an in-order traversal:
        if(curr->left!=nullptr && curr->right!=nullptr){
            //algorithm: 
            Node<KeyType, ItemType>* in = new Node<KeyType, ItemType>;
            in = nullptr; 
            Node<KeyType, ItemType>* inParent = new Node<KeyType, ItemType>;
            inParent = nullptr;

            //find the in-order successor
            inorder(curr->right, in, inParent); //in-order successor is the leftmost node of the right subtree 

            //copy the data from the in-order successor to the node flagged for deletion
            curr->key = in->key; 
            curr->data = in->data; 
                
            //delete the in-order successor
            if(inParent->left == in) inParent->left = nullptr; 
            else inParent->right = nullptr; 

            delete in; 
            inParent = nullptr; 
            delete inParent; 

            curr = nullptr; 
            delete curr; 
            parent = nullptr; 
            delete parent; 

            //done
            return true; 
        }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"
    if(curr->left == nullptr){
        in = curr; 
        return; 
    }
    inorder(curr->left, in, curr); 
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}
