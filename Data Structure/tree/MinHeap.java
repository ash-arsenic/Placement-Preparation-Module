package com.data.tree;

import com.data.Queue;

public class MinHeap {
    public int val;
    MinHeap left;
    MinHeap right;
    MinHeap parent;

    public MinHeap(int d, MinHeap p) {
        val = d;
        left = null;
        right = null;
        parent = p;
    }

    public static MinHeap insert(MinHeap root, int d) {
        Queue<MinHeap> q = new Queue<>();
        q.add(root);
        MinHeap node = root;
        while(!q.isEmpty()) {
            node = q.remove();
            if(node.left == null) {
                node.left = new MinHeap(d, node);
                node = node.left;
                break;
            } else if (node.right == null) {
                node.right = new MinHeap(d, node);
                node = node.right;
                break;
            } else {
                q.add(node.left);
                q.add(node.right);
            }
        }
        return fixHeap(node, root);
    }

    static MinHeap swap(MinHeap node1, MinHeap node2) {
        MinHeap n1Left = node1.left;
        MinHeap n1Right = node1.right;
        MinHeap n1Parent = node1.parent;

        MinHeap n2Left = node2.left;
        MinHeap n2Right = node2.right;
        MinHeap n2Parent = node2.parent;

        if(node1.left != null)
            node1.left.parent = node2;
        if(node1.right != null)
            node1.right.parent = node2;

        if(node2.left != null)
            node2.left.parent = node1;
        if(node2.right != null)
            node2.right.parent = node1;



        if(n2Parent != null && node2 == n2Parent.left) {
            n2Parent.left = node1;
        } else if (n2Parent != null && node2 == n2Parent.right) {
            n2Parent.right = node1;
        }

        if(node1 == node2.right) {
            node2.left = n1Left;
            node2.right = n1Right;
            node2.parent = node1;

            node1.right = node2;
            node1.left = n2Left;
            node1.parent = n2Parent;
        } else {
            node2.left = n1Left;
            node2.right = n1Right;
            node2.parent = node1;

            node1.left = node2;
            node1.right = n2Right;
            node1.parent = n2Parent;
        }
        return node1;
    }

    public static boolean isEmpty(MinHeap root) {
        return root == null;
    }

    static MinHeap fixHeap(MinHeap node, MinHeap root) {
        while(node.parent != null && node.val < node.parent.val) {
            swap(node, node.parent);
        }
        if(node.parent == null) {
            return node;
        }
        return root;
    }

    public static MinHeap extractMin(MinHeap root) {
        if(root == null)
            return null;

        Queue<MinHeap> q = new Queue<>();
        q.add(root);
        MinHeap node = null;
        while(!q.isEmpty()) {
            node = q.remove();
            if(node.left != null) {
                q.add(node.left);
            }
            if (node.right != null) {
                q.add(node.right);
            }
        }
        if(node == root) {
             return null;
        } else {
            if(root.left == null && node == root.right) {
                return root.right;
            } else if(root.right == null && node == root.left) {
                return root.left;
            } else if((root.right == node && root.left != null)) {
                if(root.right.val < root.left.val) {
                    root.left.parent = node;
                    node.left = root.left;
                    return node;
                } else {
                    node.parent = root.left;
                    root.left.right = node;
                    return root.left;
                }
            }
        }

        if(node.parent.right == node) {
            node.parent.right = null;
        } else if(node.parent.left == node) {
            node.parent.left = null;
        }

        node.parent = null;
        node.left = root.left;
        node.right = root.right;

        root.left.parent = node;
        root.right.parent = node;

        while(node.left != null || node.right != null) {
            if(node.left == null) {
                if(node.val > node.right.val)
                    swap(node.right, node);
                else
                    break;
            } else if(node.right == null) {
                if(node.val > node.left.val)
                    swap(node.left, node);
                else
                    break;
            } else {
                if(node.val < node.left.val && node.val < node.right.val)
                    break;

                if(node.right.val < node.left.val) {
                    swap(node.right, node);
                } else {
                    swap(node.left, node);
                }
            }
        }
        while(node.parent != null)
            node = node.parent;

        return node;
    }

    public static void print(MinHeap root) {
        if(root != null) {
            print(root.left);
            System.out.print(root.val+" ");
            print(root.right);
        }
    }

    public static int[] heapSort(int arr[]) {
        if(arr.length == 0)
            return arr;

        MinHeap h = new MinHeap(arr[0], null);
        for(int i=1; i<arr.length; i++) {
            h = insert(h, arr[i]);
        }

        int a[] = new int[arr.length];
        int ind = 0;

        while(!isEmpty(h)) {
            a[ind++] = h.val;
            System.out.println(a[ind-1]);
            h = extractMin(h);
        }
        return a;
    }
}
