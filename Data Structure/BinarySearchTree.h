#include <iostream>
#include <cstdio>
template<typename comparable>
class BinarySearchTree{
    public:
        BinarySearchTree():root{nullptr} {}

        BinarySearchTree(const BinarySearchTree & rhs): root{nullptr}{
            root = clone(rhs.root);
        }

        BinarySearchTree(BinarySearchTree && rhs): root{nullptr}{
            root = clone(rhs.root);
        }

        BinarySearchTree & operator = (const BinarySearchTree & rhs);
        BinarySearchTree & operator = (BinarySearchTree && rhs);
        ~BinarySearchTree(){
            makeEmpty();
        }

        const comparable & findMin()const{
            const node * & mi = findMin(root);
            if (mi == nullptr) ;//单独处理
            else return mi->data;
        }

        const comparable & findMax()const{
            const node * & mx = findMax(root);
            if (mx == nullptr) ;//单独处理
            else return mx->data;
        }

        bool contains(const comparable & goal)const{
            const node * & ret = contains(goal, root);
            if (ret == nullptr)
                return false;
            return goal == ret->data;
        }

        bool isEmpty()const{
            return root == nullptr;
        }

        void printTree(std::ostream & out = std::cout)const{
            printTree(out, root);
        }

        void makeEmpty(){
            makeEmpty(root);
        }

        void insert(const comparable & x){
            insert(x, root);
        }

        void insert(comparable && x){
            insert(x, root);
        }

        void remove(const comparable & x){
            remove(x, root);
        }

        void remove(comparable && x){
            remove(x, root);
        }
    
    private:
        struct node{
            comparable data;
            node * left;
            node * right;
            node(const comparable & rhs, node * l, node * r): data{rhs}, left{l}, right{r} { }
            node(comparable && rhs, node * l, node * r): data{std::move(rhs)}, left{l}, right{r} { }
        };

        node * root;
        
        void printTree(std::ostream & out, const node * & t){
            if (t == nullptr)
                return;

            printTree(out, t->left);
            printf("%d ", t->data);
            printTree(out, t->right);
        }

        void remove(const comparable & x, node * & root){
            if (root == nullptr)
                return;
            
            if (x < root->data)
                remove(x, root->left);
            else if (x > root->data)
                remove(x, root->right);
            else if (root->left != nullptr && root->right != nullptr){
                //找到右子树的左叶子 然后将左叶子remove
                root->data = findMin(root->right)->data;
                remove(root->data, root->right);
            }
            else{
                node * old = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete old;
            }
        }

        void remove(comparable && x, node * & root){
            if (root == nullptr)
                return;
            
            if (x < root->data)
                remove(x, root->left);
            else if (x > root->data)
                remove(x, root->right);
            else if (root->left != nullptr && root->right != nullptr){
                //找到右子树的左叶子 然后将左叶子remove
                root->data = findMin(root->right)->data;
                remove(root->data, root->right);
            }
            else{
                node * old = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete old;
            }
        }

        void insert(const comparable & x, node * & root){
            if (root == nullptr)
                root = new node{x, nullptr, nullptr};
            
            if (x < root->data)
                insert(x, root->left);
            else if (x > root->data)
                insert(x, root->right);
        }

        void insert(comparable && x, node * & root){
            if (root == nullptr)
                root = new node{std::move(x), nullptr, nullptr};
            
            if (x < root->data)
                insert(x, root->left);
            else if (x > root->data)
                insert(x, root->right);
        }

        void makeEmpty(node * & root){
            if (root == nullptr)
                return;
            
            makeEmpty(root->left);
            makeEmpty(root->right);
            delete root;
            root = nullptr;
        }

        const node * & contains(const comparable & goal, node * root)const{
            if (root != nullptr)
                while (root != nullptr){
                    if (goal < root->data)
                        root = root->left;
                    else if (goal > root->data)
                        root = root->right;
                    else 
                        return root;
                }
            return root;
        }

        const node * & findMin(const node * & t)const{ //最靠左的叶子结点就是最小的,返回结点会更好？
            if (t == nullptr) 
                return nullptr;
            if (t->left == nullptr) 
                return t;
            return findMin(t->left);
        }

        node * findMax(node * t)const{
            if (t == nullptr)
                return t;
            while (t->right != nullptr)
                t = t->right;
            return t;
        }

        node * clone(const node * & t){
            if (t == nullptr) return nullptr;
            return new node{t->data, clone(t->leftChild), clone(t->rightChild)};
        }
        
};

