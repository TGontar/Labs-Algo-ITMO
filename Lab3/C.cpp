//#include "iostream"
//#include "string"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
////using std::endl;
//using std::vector;
//
//#include "iostream"
//#include "string"
//#include "vector"
//
//using std::cin;
//using std::cout;
//using std::string;
////using std::endl;
//using std::vector;
//
//struct Stack {
//
//    struct Node {
//        int value;
//        Node *next;
//    };
//
//    Node *top;
//    Stack(): top(nullptr){}
//
//    void push(int v) {
//        Node *q;
//        q = new Node;
//        q->value = v;
//        q->next = nullptr;
//        if (top == nullptr) {
//            top = q;
//        } else {
//            q->next = top;
//            top = q;
//        }
//    }
//
//    int pop() {
//        if (top == nullptr) {
//            exit(0);
//        } else {
//            Node *q = top;
//            top = q->next;
//            int ret = q->value;
//            free(q);
//            return ret;
//
//        }
//    }
//
//    void printst() {
//        while (top != nullptr) {
//            Node *q = top;
//            cout << q->value << "\n";
//            top = q->next;
//        }
//    }
//
//    string isempty() {
//        if (top == nullptr) {
//            return "YES";
//        } else {
//            return "NO";
//        }
//    }
//
//    int last_elem() {
//        if (top != nullptr) {
//            return top->value;
//        } else {
//            return -1;
//        }
//    }
//};
//
//void bracket_sequence(struct Stack *stack, char v) {
//    if (stack->last_elem() == -1) {
//       stack->push(v);
//    } else if (stack->last_elem() == 40) { //чар значение для символа "("
//        if (v == 41) { //чар значение для символа ")"
//            stack->pop();
//        } else {
//            stack->push(v);
//        }
//
//    } else if (stack->last_elem() == 91) { //чар значение для символа "["
//        if (v == 93) { //чар значение для символа "]"
//            stack->pop();
//        } else {
//            stack->push(v);
//        }
//    }
//}
//
//int main() {
//    vector<string> ans;
//    while (true) {
//        Stack stack1;
//        string str;
//        std::getline(cin, str);
//        if (str.empty()) {
//            break;
//        } else {
//            int flag = 0;
//            for (int i = 0; i < str.size(); i++) {
//                char val = str[i];
//                bracket_sequence(&stack1, val);
//            }
//            string itog = stack1.isempty();
//            ans.push_back(itog);
//        }
//    }
//
//    for (int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << "\n";
//    }
//
//    return 0;
//}
