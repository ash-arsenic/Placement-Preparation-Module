package com.data.tree;

public class BST {

    private int data;
    private BST left;
    private BST right;

    public BST(int data) {
        this.data = data;
        left = null;
        right = null;
    }

    public static void inorderTraversal(BST root) {
        if(root == null) {
            return;
        }
        inorderTraversal(root.left);
        System.out.print(root.data+" ");
        inorderTraversal(root.right);
    }

    public static void preorderTraversal(BST root) {
        if(root == null) {
            return;
        }
        System.out.print(root.data+" ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    public static void postorderTraversal(BST root) {
        if(root == null) {
            return;
        }
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data+" ");
    }

    private static int successor(BST root) {
        int key = root.data;
        while (root.left != null) {
            key = root.left.data;
            root = root.left;
        }
        return key;
    }

    public static BST insert(BST root, BST node) {
        BST curr = root;
        if(root == null) {
            root = node;
            return root;
        }
        while(curr.left != null && curr.right != null) {
            if(curr.data > node.data) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }

        if(curr.data > node.data) {
            curr.left = node;
        } else {
            curr.right = node;
        }

        return root;
    }

    public static BST delete(BST root, int key) {

        if(root == null) {
            return root;
        }
        if (root.data > key) {
            root.left = delete(root.left, key);
        } else if(root.data < key) {
            root.right = delete(root.right, key);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            root.data = successor(root.right);
            root.right = delete(root.right, root.data);
        }
            return root;
        }

    public static int noOfNodes(BST root) {
        if (root == null) {
            return 0;
        }
        return 1+noOfNodes(root.left)+noOfNodes(root.right);
    }

    public static int height(BST root) {
        if (root == null) {
            return -1;
        }
        int left = height(root.left);
        int right = height(root.right);
        if (left > right) {
            return left+1;
        } else {
            return right+1;
        }
    }
}
