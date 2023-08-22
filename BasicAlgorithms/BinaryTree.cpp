//#include "iostream"
//#include "string"
//#include "math.h"
//
//using std::cin;
//using std::cout;
//
//struct BinaryTree {
//
//    struct Node {
//        int value;
//        Node *left;
//        Node *right;
//        Node *parent;
//    };
//
//    Node *root;
//    BinaryTree(): root(nullptr) {}
//
//
//    Node* createNode(int val, Node *left, Node *right, Node*parent) {
//        Node *q;
//        q = new Node;
//        q->value = val;
//        q->left = left;
//        q->right = right;
//        q->parent = parent;
//        return q;
//    }
//
//    Node *createTree(int val) {
//        root = createNode(val, nullptr, nullptr, nullptr);
//        return root;
//    }
//
//    Node *searchElement(Node *x, int k) {
//        if (x == nullptr || k == x->value) {
//            return x;
//        }
//        if (k < x->value) {
//            return searchElement(x->left, k);
//        } else {
//            return searchElement(x->right, k);
//        }
//    }
//
//    Node *insertElement(Node *x, int z) {
//        while (x != nullptr) {
//            if (z > x->value) {
//                if (x->right != nullptr) {
//                    x = x->right;
//                } else {
//                    Node *newnode = createNode(z, nullptr, nullptr, x);
//                    x->right = newnode;
//                    return newnode;
//                }
//            } else if (z < x->value) {
//                if (x->left != nullptr) {
//                    x = x->left;
//                } else {
//                    Node *newnode = createNode(z, nullptr, nullptr, x);
//                    x->left = newnode;
//                    return newnode;
//                }
//            }
//        }
//    }
//
//    Node *findMin(Node *x) {
//        if (x->left == nullptr) {
//            return x;
//        }
//
//        return findMin(x->left);
//    }
//
//    Node *findMax(Node *x) {
//        if (x->right == nullptr) {
//            return x;
//        }
//
//        return findMax(x->right);
//    }
//
//    Node *findNext(Node *x) {
//        if (x->right != nullptr) {
//            return findMin(x->right);
//        }
//        Node *y = x->parent;
//        while (y != nullptr && x == y->right) {
//            x = y;
//            y = x->parent;
//        }
//        return y;
//    }
//
//    Node *findPrev(Node *x) {
//        if (x->left != nullptr) {
//            return findMax(x->left);
//        }
//        Node *y = x->parent;
//        while (y != nullptr && x == y->left) {
//            x = y;
//            y = x->parent;
//        }
//        return y;
//    }
//
//    Node *deleteElement(Node *root, int z) {
//        Node *x = searchElement(root, z);
//        if (x == nullptr) {
//            return nullptr;
//        }
//        Node *p = x->parent;
//        if (x->left == nullptr && x->right == nullptr) {
//            if (p->left == x) {
//                p->left = nullptr;
//                return x;
//            }
//            if (p->right == x) {
//                p->right = nullptr;
//                return x;
//            }
//        } else if (x->left == nullptr || x->right == nullptr) {
//            if (x->left == nullptr) {
//                if (p->left == x) {
//                    p->left = x->right;
//                } else {
//                    p->right = x->right;
//                }
//                x->right->parent = p;
//                return x;
//            } else {
//                if (p->left == x) {
//                    p->left = x->left;
//                } else {
//                    p->right = x->left;
//                }
//                x->left->parent = p;
//                return x;
//            }
//        } else {
//            Node *tmp = x;
//            Node *s = findNext(x);
//            x->value = s->value;
//            Node *ps = s->parent;
//            if (ps->left == s) {
//                ps->left = s->right;
//                if (s->right != nullptr) {
//                    s->right->parent = s->parent;
//                }
//            } else {
//                ps->right = s->right;
//                if (s->right != nullptr) {
//                    s->right->parent = s->parent;
//                }
//            }
//            return tmp;
//        }
//    }
//
//    bool isBinaryTree(Node *x, int min, int max) {
//        if (x == nullptr) {
//            return true;
//        }
//        if (x->value <= min || x->value >= max) {
//            return false;
//        }
//        return isBinaryTree(x->left, min, x->value) && isBinaryTree(x->right, x->value, max);
//    }
//
//};
//
//
//int main() {
//    BinaryTree tree1;
//    tree1.createTree(3);
//    tree1.insertElement(tree1.root, 4);
//    tree1.insertElement(tree1.root, 5);
//    tree1.insertElement(tree1.root, 1);
//    tree1.insertElement(tree1.root, 6);
//    tree1.insertElement(tree1.root, 8);
//    tree1.insertElement(tree1.root, 10);
//    tree1.deleteElement(tree1.root, 8);
//    tree1.deleteElement(tree1.root, 3);
//    cout << tree1.isBinaryTree(tree1.root, -2111111111, 2111111111) << "\n";
//    cout << tree1.findMax(tree1.root)->value << "\n";
//    cout << tree1.findMin(tree1.root)->value << "\n";
//    return 0;
//}