package com.data.tree;

import com.data.Queue;

public class BinaryTree {
    int data;
    BinaryTree left;
    BinaryTree right;

    public BinaryTree(int d) {
        data = d;
        left = null;
        right = null;
    }

    public static void add(BinaryTree root, int d) {
        Queue<BinaryTree> q = new Queue<>();
        q.add(root);
        while(!q.isEmpty()) {
            BinaryTree node = q.remove();
            if(node.left == null) {
                node.left = new BinaryTree(d);
                break;
            } else if (node.right == null) {
                node.right = new BinaryTree(d);
                break;
            } else {
                q.add(node.left);
                q.add(node.right);
            }
        }
    }

    public static void delete(BinaryTree root, int val) {
        if(root == null || root.left == null && root.right == null)
            return;

        if(root.left.data == val) {
            root.left = root.left.left;
        } else if(root.right.data == val) {
            root.right = root.right.right;
        } else {
            delete(root.left, val);
            delete(root.right, val);
        }
    }

    public static void print(BinaryTree root) {
        if(root != null) {
            print(root.left);
            System.out.print(root.data+" ");
            print(root.right);
        }
    }
}
