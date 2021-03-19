#include <iostream>
#include <memory>


struct Btree{
    int val;
    std::shared_ptr<Btree> left;
    std::shared_ptr<Btree> right;
    Btree(int value) : val(value), left(nullptr), right(nullptr)
    {}

};

std::shared_ptr<Btree> maketree(int value){
    return std::make_shared<Btree>(value);
}

void InsertNode(std::shared_ptr<Btree> bst, int value){
    while(1){
        if(value > bst->val){
                if(bst->right == nullptr){
                bst->right = maketree(value);
                break;
                }
                else{
                    bst = bst-> right;
                    continue;
                }
        }
        else if(value < bst->val){
                if (bst-> left == nullptr){
                    bst->left = maketree(value);
                    break;
                }
                else{
                    bst = bst->left;
                    continue;
                }
        }
        else{
            std::cout << "No duplicaates\n";
            break;
        }
    }

}

void Printbst(std::shared_ptr<Btree> bst){
    if(bst->left  != nullptr)
        Printbst(bst->left);
    std::cout<< "Node Value =>" << bst ->val << "\n";
    if(bst->right != nullptr)
        Printbst(bst->right);
}


int main(){
    //Test step 1 -
    std::shared_ptr<Btree> bst = maketree(8);
    if (bst == nullptr){
        std::cout << "BST creation Failed\n";
    }
    else{
        std::cout << "BST creation Succesful\n";
    }
    //Test step - 2

    InsertNode(bst, 1);
    InsertNode(bst, 3);
    InsertNode(bst, 4);
    InsertNode(bst, 6);
    InsertNode(bst, 7);
    InsertNode(bst, 9);
    InsertNode(bst, 11);
    InsertNode(bst, 13);
    InsertNode(bst, 15);
    InsertNode(bst, 17);


    //Test step - 3

    Printbst(bst);
return 0;
}
