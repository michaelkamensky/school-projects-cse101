/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#7
* Dictionary.cpp 
* The defintions for the Dictionary ADT uses Binary Trees to simulate the dictionary construct
*********************************************************************************/ 
#include<iostream>
#include<string>
#include<string.h>
#include"Dictionary.h"

#define DEBUG 0

#define NONE 0 // defining the color None for debuging purposes
#define RED 1 // defining the color red for program read ability
#define BLACK 2 // defining the color balck for program read ability


// Helper Functions (Optional) ---------------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        inOrderString(s, R->left);
        s += R->key + " : " + std::to_string(R->val) + "\n";
        inOrderString(s, R->right);
    }

}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
#if 0
        if (R->color == BLACK) {
            s += R->key + "\n";
        } else {
            s += R->key + " (RED)\n";
        }
#endif
        s += R->key + "\n";
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }
}

// BST_insert()
// Inserts a copy of the Node *M into this Dictionary. Used by preOrderCopy().
void Dictionary::BST_insert(Node* M) {
    Node* y = nil;
    Node* x = root;
    while (x != nil) {
        y = x;
        if (M->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    M->parent = y;
    if (y == nil) {
        root = M;    // tree T was empty
    }
    else if (M->key < y->key) {
        y->left = M;
    }
    else {
        y->right = M;
    }
}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    if (R != N) {
        Node* insert = new Node(R->key, R->val);
        insert->color = R->color;
        insert->left = nil;
        insert->right = nil;
        BST_insert(insert);
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
    if (R != nil) {
        while (R->right != nil) {
            R = R->right;
        }
        return R;
    }else {
        return nil;
    }
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N == findMax(root)) {
        return nil;
    } else {
        if (N->right != nil) {
            return findMin(N->right);
        } else {
            // climbig up if we comming from the right side
            // we skip this parent because it was already visited
            Node* cur = N;
            Node* parent = N->parent;
            while (parent->right == cur){
                cur = parent;
                parent = cur->parent;
            }
            return parent;
        }
    }
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N) {
    if (N == findMin(root)) {
        return nil;
    } else {
        if (N->left != nil) {
            return findMax(N->left);
        } else {
            // climbig up if we comming from the left side
            // we skip this parent because it was already visited
            Node* cur = N;
            Node* parent = N->parent;
            while (parent->left == cur){
                cur = parent;
                parent = cur->parent;
            }
            return parent;
        }
    }
}

// RBT Helper Functions (Optional) -----------------------------------------
   
// LeftRotate()
void Dictionary::LeftRotate(Node* N) {
    // set y
    Node* y = N->right;
   
    // turn y's left subtree into x's right subtree
    N->right = y->left;
    if (y->left != nil) {     // not necessary if using sentinal nil node
        y->left->parent = N;
    }
    // link y's parent to x
    y->parent = N->parent; 
    if (N->parent == nil) {
        root = y;
    }
    else if (N == N->parent->left) {
        N->parent->left = y;
    }
    else {
        N->parent->right = y;
    }
   
    // put x on y's left
    y->left = N;
    N->parent = y;
}

// RightRotate()
void Dictionary::RightRotate(Node* N) {
    // set y
    Node* y = N->left;
   
    // turn y's left subtree into x's right subtree
    N->left = y->right;
    if (y->right != nil) {     // not necessary if using sentinal nil node
        y->right->parent = N;
    }
    // link y's parent to x
    y->parent = N->parent; 
    if (N->parent == nil) {
        root = y;
    }
    else if (N == N->parent->right) {
        N->parent->right = y;
    }
    else {
        N->parent->left = y;
    }
   
    // put x on y's left
    y->right = N;
    N->parent = y;
}

// RB_InsertFixUP()
void Dictionary::RB_InsertFixUp(Node* N) {
    while (N->parent->color == RED) {
        if (N->parent == N->parent->parent->left) {
            Node* y = N->parent->parent->right;
            if (y->color == RED) {
                N->parent->color = BLACK ;             // case 1
                y->color = BLACK;                     // case 1
                N->parent->parent->color = RED;         // case 1
                N = N->parent->parent;                 // case 1
            }
            else {
                if (N == N->parent->right) {
                    N = N->parent;                     // case 2
                    LeftRotate(N);                    // case 2
                }
                N->parent->color = BLACK;              // case 3
                N->parent->parent->color = RED;          // case 3
                RightRotate(N->parent->parent);         // case 3
            }
        }
        else {
            Node* y = N->parent->parent->left;
            if (y->color == RED) {
                N->parent->color = BLACK;              // case 4
                y->color = BLACK;                     // case 4
                N->parent->parent->color = RED;         // case 4
                N = N->parent->parent;                 // case 4
            }
            else {
                if (N == N->parent->left) {
                    N = N->parent;                     // case 5
                    RightRotate(N);                // case 5
                }
                N->parent->color = BLACK;              // case 6
                N->parent->parent->color = RED;         // case 6
                LeftRotate(N->parent->parent);     // case 6
            }
        }
    }
    root->color = BLACK;
}

// RB_Transplant()
void Dictionary::RB_Transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else { 
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// RB_DeleteFixUp()
void Dictionary::RB_DeleteFixUp(Node* N) {
    while (N != root && N->color == BLACK) {
        if (N == N->parent->left) {
            Node* w = N->parent->right;
            if (w->color == RED) {
                w->color = BLACK;                      // case 1
                N->parent->color = RED;                  // case 1
                LeftRotate(N->parent);                // case 1
                w = N->parent->right;                     // case 1
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;                          // case 2
                N = N->parent;                           // case 2
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;                // case 3
                    w->color = RED;                       // case 3
                    RightRotate(w);                   // case 3
                    w = N->parent->right;                  // case 3
                }
                w->color = N->parent->color;               // case 4
                N->parent->color = BLACK;                 // case 4
                w->right->color = BLACK;                  // case 4
                LeftRotate(N->parent);                // case 4
                N = root;                             // case 4
            }
        }
        else {
            Node* w = N->parent->left;
            if (w->color == RED) {
                w->color = BLACK;                       // case 5
                N->parent->color = RED;                   // case 5
                RightRotate(N->parent);               // case 5
                w = N->parent->left;                      // case 5
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;                          // case 6
                N = N->parent;                           // case 6
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;               // case 7
                    w->color = RED;                       // case 7
                    LeftRotate(w);                    // case 7
                    w = N->parent->left;                   // case 7
                }
                w->color = N->parent->color;               // case 8
                N->parent->color = BLACK;                 // case 8
                w->left->color = BLACK;                   // case 8
                RightRotate(N->parent);               // case 8
                N = root;                             // case 8
            }
        }
    }
   N->color = BLACK;
}

// RB_Delete()
void Dictionary::RB_Delete(Node* N) {
    Node* y = N;
    Node* x;
    int y_original_color = y->color;
    if (N->left == nil) {
        x = N->right;
        RB_Transplant(N, N->right);
    }
    else if (N->right == nil) {
        x = N->left;
        RB_Transplant(N, N->left);
    }
    else {
        y = findMin(N->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == N) {
            x->parent = y;
        }
        else {
            RB_Transplant(y, y->right);
            y->right = N->right;
            y->right->parent = y;
        }
        RB_Transplant(N, y);
        y->left = N->left;
        y->left->parent = y;
        y->color = N->color;
    }
    if (y_original_color == BLACK) { 
        delete N;
        RB_DeleteFixUp(x);
    }
    
}

// Class Constructors & Destructors ----------------------------------------

Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    color = NONE;
    parent = NULL;
    left = NULL;
    right = NULL;

}

// Creates new Dictionary in the empty state. 
Dictionary::Dictionary() {
    num_pairs = 0;
    nil = new Node("", 0);
    nil->color = BLACK;
    root = nil;
    root->parent = nil;
    current = nil;
}

// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    num_pairs = D.num_pairs;
    nil = new Node("", 0);
    nil->color = BLACK;
    root = nil;
    current = nil;
    preOrderCopy(D.root, D.nil);
    
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
        throw std::invalid_argument("Dictionary: getValue(): key \"" + k + "\" does not exist");
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
        throw std::invalid_argument("Dictionary: currentKey(): current undefined");
    }
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const {
    if(hasCurrent()) {
        return current->val;
    }else {
        throw std::invalid_argument("Dictionary: currentVal(): current undefined");
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
    num_pairs += 1;
    Node* z = new Node(k, v); 
    Node* y = nil;
    Node* x = root;
    while (x != nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } 
        else if (z->key == x->key) {
            x->val = v;
            num_pairs -= 1;
            delete z;
            return;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nil) {
        root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = RED;
    RB_InsertFixUp(z);
}

// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k) {
    if (!contains(k)){
        throw std::invalid_argument("Dictionary: remove(): key \"" + k + "\" does not exist");
    } else {
        Node* N = search(root, k);
        if (N == current) {
            current = nil;
        }
        RB_Delete(N);
        num_pairs -= 1;
    }
}

// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::begin() {
    if (num_pairs == 0) {
        throw std::invalid_argument("begin(): the dictionary is empty");
    }
    current = findMin(root);
}

// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::end() {
    if (num_pairs == 0) {
        throw std::invalid_argument("end(): the dictionary is empty");
    }
    current = findMax(root);
}

// next()
// If the current iterator is not at the last pair, advances current 
// to the next pair (as defined by the order operator < on keys). If 
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next() {
    if (hasCurrent()) {
        Node* advance = findNext(current);
        current = advance;
    } else {
        throw std::invalid_argument("Dictionary: next(): current undefined");
    }
}

// prev()
// If the current iterator is not at the first pair, moves current to  
// the previous pair (as defined by the order operator < on keys). If 
// the current iterator is at the first pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::prev() {
    if (hasCurrent()) {
        Node* advance = findPrev(current);
        current = advance;
    } else {
        throw std::invalid_argument("Dictionary: prev(): current undefined");
    }
}

// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value 
// are separated by the sequence space-colon-space " : ". The pairs are arranged 
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const {
    std::string result;
    inOrderString(result, root);
    return result;
}

// pre_string()
// Returns a string consisting of all keys in this Dictionary. Consecutive
// keys are separated by newline "\n" characters. The key order is given
// by a pre-order tree walk.
std::string Dictionary::pre_string() const {
    std::string result;
    preOrderString(result, root);
    return result;
}

// equals()
// Returns true if and only if this Dictionary contains the same (key, value)
// pairs as Dictionary D.
bool Dictionary::equals(const Dictionary& D) const {
    if (num_pairs != D.num_pairs) {
        return false;
    }
    std::string result1;
    inOrderString(result1, root);
    std::string result2;
    D.inOrderString(result2, D.root);

    if (result1.compare(result2) == 0) {
        return true;
    } else {
        return false;
    }

}

// Overloaded Operators ----------------------------------------------------
   
// operator<<()
// Inserts string representation of Dictionary D into stream, as defined by
// member function to_string().
std::ostream& operator<<( std::ostream& stream, Dictionary& D ) {
    return stream << D.Dictionary::to_string();
}

// operator==()
// Returns true if and only if Dictionary A equals Dictionary B, as defined
// by member function equals(). 
bool operator==( const Dictionary& A, const Dictionary& B ) {
    return A.equals(B);
}

// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ) {
    clear();
    preOrderCopy(D.root, D.nil);
    num_pairs = D.num_pairs;
    return *this;
}

