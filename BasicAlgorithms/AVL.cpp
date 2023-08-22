//#include "iostream"
//#include "string"
//#include "math.h"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
//using std::vector;
//using std::to_string;
//
//struct BinaryTree {
//
//    struct Node {
//        int value;
//        int balance;
//        Node *left;
//        Node *right;
//        Node *parent;
//    };
//
//    Node *root;
//    Node *tmp;
//
//    BinaryTree() : root(nullptr), tmp(nullptr) {}
//
//
//    Node *createNode(int val, int bal, Node *left, Node *right, Node *parent) {
//        Node *q;
//        q = new Node;
//        q->value = val;
//        q->balance = bal;
//        q->left = left;
//        q->right = right;
//        q->parent = parent;
//        return q;
//    }
//
//    Node *createTree(int val) {
//        root = createNode(val, 0, nullptr, nullptr, nullptr);
//        return root;
//    }
//
//    void fixHeight(Node *q) {
//        if (q->parent != nullptr) {
//            while (q->parent != nullptr) {
//                Node *p = q->parent;
//                if (q == p->left) {
//                    p->balance -= 1;
//                } else {
//                    p->balance += 1;
//                }
//                q = p;
//            }
//        }
//    }
//
//    Node *rotateLeft(Node *q) {
//        Node *p = q->right;
//        q->right = p->left;
//        p->left = q;
//        fixHeight(q);
//        fixHeight(p);
//        return p;
//    }
//
//    Node *rotateRight(Node *q) {
//        Node *p = q->left;
//        q->left = p->right;
//        p->right = q;
//        fixHeight(q);
//        fixHeight(p);
//        return p;
//    }
//
//    Node *bigRotateLeft(Node *q) {
//        rotateRight(q->right);
//        rotateLeft(q);
//        return q;
//    }
//
//    Node *bigRotateRight(Node *q) {
//        rotateLeft(q->left);
//        rotateRight(q);
//        return q;
//    }
//
//    Node *balanceTree(Node *q) {
//        fixHeight(q);
//        if (q->balance == 2) {
//            if (q->right->balance < 0) {
//                return bigRotateLeft(q);
//            } else {
//                return rotateLeft(q);
//            }
//        } else if (q->balance == -2) {
//            if (q->left->balance > 0) {
//                return bigRotateRight(q);
//            } else {
//                return rotateRight(q);
//            }
//        } else {
//            return q;
//        }
//    }
//
//    Node *insertNode(Node *x, int k) {
//        if (x == nullptr) {
//            return createTree(k);
//        }
//        if (k < x->value) {
//            if (x->left == nullptr) {
//                Node *newnode = createNode(k, 0, nullptr, nullptr, x);
//                x->left = newnode;
//                return balanceTree(newnode);
//            } else {
//                x->left = insertNode(x->left, k);
//            }
//        } else {
//            if (x->right == nullptr) {
//                Node *newnode = createNode(k, 0, nullptr, nullptr, x);
//                x->right = newnode;
//                return balanceTree(newnode);
//            } else {
//                x->right = insertNode(x->right, k);
//            }
//        }
//        return balanceTree(x);
//    }
//
//    Node *deleteNode(Node *x, int k) {
//        if (searchElement(x, k) == nullptr) {
//            return nullptr;
//        }
//        if (k < x->value) {
//            x->left = deleteNode(x->left, k);
//        } else if (k > x->value) {
//            x->right = deleteNode(x->right, k);
//        } else {
//            Node *max = findMax(x->left);
//            if (max == nullptr) {
//                if (x->right != nullptr) {
//                    if (x->parent == nullptr) {
//                        x->value = x->right->value;
//                        x->right = nullptr;
//                    } else {
//                        if (x->parent->right == x) {
//                            x->parent->right = x->right;
//                        } else {
//                            x->parent->left = x->right;
//                        }
//                    }
//                } else {
//                    if (x->parent== nullptr) {
//                        return nullptr;
//                    } else {
//                        if (x->parent->right == x) {
//                            x->parent->right = nullptr;
//                        } else {
//                            x->parent->left = nullptr;
//                        }
//                    }
//                }
//            }
//            if (max->left != nullptr) {
//                max->parent->right = max->left;
//            } else {
//                max->left->right = nullptr;
//            }
//            x->value = max->value;
//        }
//        return balanceTree(x);
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
//    int findNextInt(Node *x, int k) {
//        if (x == nullptr) {
//            return k;
//        }
//        Node *current = x;
//        Node *successor = x;
//        while (current != nullptr) {
//            if (current->value <= k) {
//                current = current->right;
//            } else {
//                successor = current;
//                current = current->left;
//            }
//        }
//        return successor->value;
//    }
//
//    int findPrevInt(Node *x, int k) {
//        if (x == nullptr) {
//            return k;
//        }
//        Node *current = x;
//        Node *successor = x;
//        while (current != nullptr) {
//            if (current->value >= k) {
//                current = current->left;
//            } else {
//                successor = current;
//                current = current->right;
//            }
//        }
//        return successor->value;
//    }
//
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
//    vector<string> ans;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        string inp;
//        cin >> inp;
//        int val;
//        cin >> val;
//        if (inp == "A") {
//            tree1.tmp = tree1.insertNode(tree1.root, val);
//            ans.push_back(std::to_string(tree1.root->balance));
//        } else if (inp == "C") {
//            tree1.tmp = tree1.searchElement(tree1.root, val);
//            if (tree1.tmp == nullptr) {
//                ans.push_back("N");
//            } else {
//                ans.push_back("Y");
//            }
//        } else {
//            tree1.tmp = tree1.deleteNode(tree1.root, val);
//            ans.push_back(std::to_string(tree1.root->balance));
//        }
//
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}