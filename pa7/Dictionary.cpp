/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#6
* BigInteger.cpp 
* A BigInteger ADT that creates a large int through a list of longs that can be added subtracted and mulitplied with other big ints
*********************************************************************************/ 
#include<iostream>
#include<string>
#include"Dictionary.h"

#define DEBUG 0


// Helper Functions (Optional) ---------------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {

}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    if (R != N) {
        // print(x.key);
        preOrderCopy(R->left, N);
        preOrderCopy(R->right, N);
    }
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R.
void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        postOrderDelete(R->left);
        postOrderDelete(R->right);
        delete R;
    }
}

// search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
    if (R == nil) {
        return nil;
    } 
    if ( k == R->key) {
        return R;
    }
    else if (k < R->key) {
        return search(R->left, k);
    }
    else { // k > x.key
        return search(R->right, k);
    }
}

// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R) {
    if (R != nil) {
        while (R->left != nil) {
            R = R->left;
        }
        return R; 
    }else {
        return nil;
    }
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
    return nil;
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N) {
    return nil;
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N) {
    return nil;
}

// Class Constructors & Destructors ----------------------------------------

Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = NULL;
    left = NULL;
    right = NULL;
}



// Creates new Dictionary in the empty state. 
Dictionary::Dictionary() {
    num_pairs = 0;
    nil = new Node("", 0);
    root = nil;
    root->parent = nil;
    current = nil;
}

// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    num_pairs = D.num_pairs;
    nil = D.nil;
    root = D.root;
    current = D.current;
    
}

// Destructor
Dictionary::~Dictionary() {
    postOrderDelete(root);
    delete nil;
}


// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const {
    return num_pairs;
}

// contains()
// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const {
    Node* res = search(root, k);
    if (res != nil) {
        return true;
    }
    else {
        return false;
    }
}

// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const {
    if(contains(k)) {
        Node* n = search(root, k);
        return n->val;
    } else {
        throw std::invalid_argument("getValue(): k does not exist");
    }
}

// hasCurrent()
// Returns true if the current iterator is defined, and returns false 
// otherwise.
bool Dictionary::hasCurrent() const {
    if (current != nil) {
        return true;
    } else {
        return false;
    }
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent() 
keyType Dictionary::currentKey() const {
    if(hasCurrent()) {
        return current->key;
    } else {
        throw std::invalid_argument("currentKey(): current does not exist");
    }
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const {
    if(hasCurrent()) {
        return current->val;
    }else {
        throw std::invalid_argument("currentVal(): current does not exist");
    }
}

// Manipulation procedures -------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear() {
    postOrderDelete(root);
    num_pairs = 0;
    root = nil;
    root->parent = nil;
    current = nil;
}

// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v, 
// otherwise inserts the new pair (k, v).
void Dictionary::setValue(keyType k, valType v) {
    if(contains(k)) {
        Node* n = search(root, k);
        n->val = v;
    } // else the value does not exist 
    else {
        Node* insert = new Node(k, v);
        num_pairs += 1;
        insert->left = nil;
        insert->right = nil;
        Node* y = nil;
        Node* x = root;
        while (x != nil) {
            y = x;
            if (insert->key < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        insert->parent = y;
        if (y == nil) {
            root = insert;   // tree T was empty
        }
        else if (insert->key < y->key) {
            y->left = insert;
        }
        else {
            y->right = insert;
        }
    }
}

// helper for delete
void Dictionary::transplant(Node* root, Node* u, Node* v) const {
    if (u->parent == nil) {
        root = u->right;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != nil) {
        v->parent = u->parent;
    }
}


// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k) {
    if (!contains(k)){
        throw std::invalid_argument("remove(): k does not exist");
    }
    Node* z = search(root, k);
    if (z->left == nil) {               // case 1  or case 2.1 (right only)
        transplant(root, z, z->right);
    }
    else if (z->right == nil) {       // case 2.2 (left only)
        transplant(root, z, z->left);
    }
    else {                           // case 3
        Node* y = findMin(z->right);
        if (y->parent != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left->parent = y;
    }
}