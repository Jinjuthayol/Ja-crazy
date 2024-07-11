#ifndef bst_h
#define bst_h

#include "doctor.h"
#include "urgency.h"

class TreeNode {
public:
    Urgency* urgency;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Urgency* u) : urgency(u), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, Urgency* urgency) {
        if (node == nullptr) {
            return new TreeNode(urgency);
        }
        if (urgency->urgencyLevel < node->urgency->urgencyLevel) {
            node->left = insert(node->left, urgency);
        } else {
            node->right = insert(node->right, urgency);
        }

        return node;
    }

    /*void inorder(TreeNode* node) const {
        if (node != nullptr) {
            inorder(node->left);
            cout << "Urgency Level " << node->urgency->urgencyLevel << " for Doctor "
                 << node->urgency->doctorName << ":" << endl;
            node->urgency->doctor->printPatientsByUrgency();
            cout << endl;
            inorder(node->right);
        }
    }*/

public:
    BST() : root(nullptr) {}

    void insert(Urgency* urgency) {
        root = insert(root, urgency);
    }

    /*void printPatientsByUrgency() const {
        inorder(root);
    }*/
};

#endif
