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
//    int last_elem() {
//        if (top != nullptr) {
//            return top->value;
//        } else {
//            return -1;
//        }
//    }
//
//
//
//};
//
//void postfix(struct Stack *stack, char v) {
//    if (stack->top == nullptr) {
//        int newval = v - '0';
//        stack->push(newval);
//    } else if (v == 43) { //чар значение символа "+"
//        int second = stack->pop();
//        int first = stack->pop();
//        int newval = first + second;
//        stack->push(newval);
//    } else if (v == 45) { //чар значение символа "-"
//        int second = stack->pop();
//        int first = stack->pop();
//        int newval = first - second;
//        stack->push(newval);
//    } else if (v == 42) { //чар значение символа "*"
//        int second = stack->pop();
//        int first = stack->pop();
//        int newval = first * second;
//        stack->push(newval);
//    } else {
//        int newval = v - '0';
//        stack->push(newval);
//    }
//}
//
//int main() {
//    Stack stack1;
//    string str;
//    std::getline(cin, str);
//    for (int i = 0; i < str.size(); i = i+2) {
//        char k = str[i];
//        postfix(&stack1, k);
//    }
//
//    stack1.printst();
//    return 0;
//}
