#include <iostream>
#include <cstdio>
#include <algorithm>
template<typename comparable>
class AvlTree{
    public:
        int getMaxHeight()const{
            return get_height(root);
        }
        
    private:
        static const int Allowed_Imbalance = 1;
        struct Avlnode{
            comparable data;
            Avlnode * left;
            Avlnode * right;
            int height;

            Avlnode(const comparable & rhs, Avlnode * l, Avlnode * r, int h = 0): 
            data{rhs}, left{l}, right{r}, height{h} { }
            Avlnode(comparable && rhs, Avlnode * l, Avlnode * r, int h = 0): 
            data{std::move(rhs)}, left{l}, right{r}, height{h} { }
        };

        Avlnode * root;
        
        int get_height(const Avlnode * t)const{
            return t == nullptr ? -1 : t->height;
        }

        void balance(Avlnode * & t){
            if (get_height(t->left) - get_height(t->right) > Allowed_Imbalance)
                if (get_height(t->left->left) >= get_height(t->left->right))
                    rotateWithLeftChild(t);
                else 
                    doubleWithLeftChild(t);
            else if (get_height(t->right) - get_height(t->left) > Allowed_Imbalance)
                if (get_height(t->right->right) >= get_height(t->right->left))
                    rotateWithRightChild(t);
                else 
                    doubleWithRightChild(t);

            t->height = std::max(get_height(t->left), get_height(t->right)) + 1; //更新高度
        }

         //单旋转就是将深度较深的那个子树变成（第一个被破坏AVL性质的）树的根节点，原本的根节点变成现在的左（右）子树
        void rotateWithLeftChild(Avlnode * & k2){
            Avlnode * k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = std::max(get_height(k2->left), get_height(k2->right)) + 1;
            k1->height = std::max(get_height(k1->left), k2->height) + 1;
            k2 = k1;
        }

        void rotateWithRightChild(Avlnode * & k2){
            Avlnode * k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = std::max(get_height(k2->left), get_height(k2->right)) + 1;
            k1->height = std::max(get_height(k1->left), k2->height) + 1;
            k2 = k1;
        }

        //双旋转：将最下面那个结点旋转到最上面，可以由两次单旋转组成
        //先将最下面那个结点和靠近它的父结点旋转一次，这时候父结点会变成它的左（右）子结点；然后，再将当前这个结点和根节点（此时的父结点）做一次单旋转
        void doubleWithLeftChild(Avlnode * & k3){
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        void insert(const comparable & x, Avlnode * & root){
            if (root == nullptr)
                root = new Avlnode{x, nullptr, nullptr};
            
            if (x < root->data)
                insert(x, root->left);
            else if (x > root->data)
                insert(x, root->right);
            
            balance(root);   //每次插入操作，回溯到根结点的路径上的所有点都会检测平衡，不平衡就balance，并且会从“深到浅”更新一波每个结点的高度。
        }

        void insert(comparable && x, Avlnode * & root){
            if (root == nullptr)
                root = new Avlnode{std::move(x), nullptr, nullptr};
            
            if (x < root->data)
                insert(x, root->left);
            else if (x > root->data)
                insert(x, root->right);
            balance(root);
        }
        
        void doubleWithRightChild(Avlnode * & k3){
            rotateWithLeftChild(k3->right);
            rotateWithRightChild(k3);
        }

        void remove(const comparable & x, Avlnode * & root){
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
                Avlnode * old = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete old;
            }
            balance(root);     //删除结点后的平衡操作和插入节点后的一样
        }

        void remove(comparable && x, Avlnode * & root){
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
                Avlnode * old = root;
                root = (root->left == nullptr ? root->right : root->left);
                delete old;
            }
            balance(root);
        }

        
};

