#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include <string>

using namespace std;

/* ------------------------------ */
/* --------- CLASS Node --------- */
/* ------------------------------ */

class Node
{
    private:
        /* ATTRIBUTES */
        
        /**
          * @brief Value of the node.
          */
        string data;

        /**
          * @brief Left-child node.
          */
        Node* left;

        /**
          * @brief Right-child node.
          */
        Node* right;

    public:
        /* CONSTRUCTORS */

        /** 
         *  @brief Default constructor
         *  @note  The 'Node' pointers are initialised to 'nullptr' and 'data' to empty string.
         */
        Node();

        /** 
         *  @brief Parameterised constructor
         *  @param data value of the node
         *  @note  The 'Node' pointers are initialised to 'nullptr'.
         */
        Node(string data);


        /* DESTRUCTOR */

        /** 
         *  @brief Destructor
         *  @note  Remove, in memory, the node (delete the node pointers).
         */
        ~Node();


        /* GET METHODS */

        /** 
         *  @brief  Get the value of the node.
         *  @param  none
         *  @return 'data'
         */
        string getData() const;

        /** 
         *  @brief  Get the left-child node.
         *  @param  none
         *  @return 'left'
         */
        Node* getLeft() const;

        /** 
         *  @brief  Get the right-child node.
         *  @param  none
         *  @return 'right'
         */
        Node* getRight() const;


        /* SET METHODS */

        /** 
         *  @brief  Set the value of the node.
         *  @param  data value of the node
         *  @return void
         */
        void setData(string data);

        /** 
         *  @brief  Set the left-child node.
         *  @param  left
         *  @return void
         */
        void setLeft(Node* left);

        /** 
         *  @brief  Set the right-child node.
         *  @param  right
         *  @return void
         */
        void setRight(Node* right);
};

/* ------------------------------ */
/* ----- CLASS DecisionTree ----- */
/* ------------------------------ */

class DecisionTree
{
    private:
        /**
          * @brief Root of the tree.
          */
        Node* root;

    public:
        /* CONSTRUCTOR */

        /** 
         *  @brief Default constructor
         *  @note  The 'root' is initialised to 'nullptr'.
         */
        DecisionTree();


        /* DESTRUCTOR */

        /** 
         *  @brief Destructor
         *  @note  Tree removal in memory (delete the root).
         */
        ~DecisionTree();


        /* GET METHODS */

        /** 
         *  @brief  Get the root node of the tree.
         *  @param  none
         *  @return 'root'
         */
        Node* getRoot() const;


        /* SET METHODS */

        /** 
         *  @brief  Set the root node of the tree.
         *  @param  root
         *  @return void
         */
        void setRoot(Node* root);


        /* OTHER METHODS */

        /** 
         *  @brief  Search node with a given value.
         *  @param  searching pointer to the node where the search is starting
         *  @param  value 'data' of the node to find
         *  @return Pointer to the node found.
         */
        Node* searchNode(Node* searching, string value);

        /** 
         *  @brief  Insert a new node in the tree.
         *  @param  predecessor 'data' of the parent of the node to insert
         *  @param  value 'data' of the node to insert
         *  @param  decision "Yes" or "No" string to indicate the placement of the node, right or left subtree
         *  @return -1 if error || 0 if successful
         */
        int insert(string predecessor, string value, string decision);

        /** 
         *  @brief  Preorder traversal of the tree.
         *  @param  tree_node node to start the traversal
         *  @return void
         */
        void preOrderTraversal(Node* tree_node);

        /** 
         *  @brief  Populate tree using a text file.
         *  @param  filename filename of the text file containing the nodes' information
         *  @return -1 if error || 0 if successful
         *  @note   Each line of the file has the information for a new node of the tree and follows the format:
         *  @note   data | data_of_parent_node | decision (separated by tabs)
         *  @note   The decision is either "No" or "Yes", corresponding to the placement of the new node, left or right child, respectively.
         */
        int import(const string filename);
};

#endif