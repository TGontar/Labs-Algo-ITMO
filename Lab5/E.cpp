//void delete_bin_tree(int val) {
//    Node* newNode = exists(val, root);
//    if (newNode == nullptr) {
//        return;
//    }
//    if (newNode == root) {
//        if (newNode->left == nullptr && newNode->right == nullptr) {
//            root = nullptr;
//        } else if (newNode->left != nullptr && newNode->right != nullptr) {
//            newNode = newNode->right;
//            while (newNode->left != nullptr) {
//                newNode = newNode->left;
//            }
//            if (newNode->parent == root) {
//                newNode->parent = nullptr;
//                newNode->left = root->left;
//                root = newNode;
//            } else {
//                if (newNode->right != nullptr) {
//                    newNode->parent->left = newNode->right;
//                    root->val = newNode->val;
//                } else {
//                    newNode->parent->left = nullptr;
//                    root->val = newNode->val;
//                }
//            }
//        } else {
//            if (newNode->left != nullptr) {
//                newNode->left->parent = nullptr;
//                root = newNode->left;
//            } else {
//                newNode = newNode->right;
//                while (newNode->left != nullptr) {
//                    newNode = newNode->left;
//                }
//                if (newNode->parent == root) {
//                    newNode->parent = nullptr;
//                    root = newNode;
//                } else {
//                    if (newNode->right != nullptr) {
//                        newNode->parent->left = newNode->right;
//                        root->val = newNode->val;
//                    }
//                }
//            }
//        }
//    } else {
//        Node *p = newNode->parent;
//        if (newNode->left == nullptr && newNode->right == nullptr) {
//            if (p->left == newNode) {
//                p->left = nullptr;
//                return;
//            } else {
//                p->right = nullptr;
//                return;
//            }
//        } else if (newNode->left == nullptr || newNode->right == nullptr) {
//            if (newNode->left == nullptr) {
//                if (p->left == newNode) {
//                    p->left = newNode->right;
//                } else {
//                    p->right = newNode->right;
//                }
//                newNode->right->parent = p;
//            } else {
//                if (p->left == newNode) {
//                    p->left = newNode->left;
//                } else {
//                    p->right = newNode->left;
//                }
//                newNode->left->parent = p;
//            }
//        } else {
//            Node* successor = newNode;
//            successor = successor->right;
//            while (successor->left != nullptr) {
//                successor = successor->left;
//            }
//            newNode->val = successor->val;
//            if (successor->parent->left == successor) {
//                successor->parent->left = successor->right;
//                if (successor->right != nullptr) {
//                    successor->right->parent = successor->parent;
//                }
//            } else {
//                successor->parent->right = successor->right;
//                if (successor->right != nullptr) {
//                    successor->right->parent = successor->parent;
//                }
//            }
//        }
//    }
//}
//};