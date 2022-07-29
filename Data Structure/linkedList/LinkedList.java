package com.data.linkedList;

public class LinkedList {
    private int data;
    private LinkedList next;

    public LinkedList(int data) {
        this.data = data;
        next = null;
    }
    public static void print(LinkedList head) {
        if(head == null) {
            System.out.println("List is empty");
            return;
        }
        LinkedList temp = head;
        while(temp != null) {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.print("\n");
    }

    public static int find(LinkedList head, int key) {
        LinkedList temp = head;
        int pos = 0;
        while(temp!=null) {
            if(temp.data == key) {
                return pos;
            }
            pos++;
            temp = temp.next;
        }
        return -1;
    }

    public static LinkedList swap(LinkedList head, int first, int second) {
        LinkedList temp = head;
        LinkedList firstNode = null;
        LinkedList secondNode = null;
        int flag = 0;
//        Element doesn't exist
        if(find(head, first) == -1 || find(head, second) == -1) {
            return head;
        }

//        head needed to swap
        if(temp.data == first) {
            firstNode = temp;
            flag = 1;
        }
        while(temp!=null && (firstNode==null || secondNode==null)) {
            if(temp.next.data == first) {
                firstNode = temp;
            }
            if(temp.next.data == second) {
                secondNode = temp;
            }
            temp = temp.next;
        }

//        For 1st and last
        if(flag == 1) {
            LinkedList t = secondNode.next;
            secondNode.next.next = firstNode.next;
            secondNode.next = firstNode;
            firstNode.next = null;
            head = t;
            return head;
        }

        LinkedList t = secondNode.next.next;
        LinkedList u = secondNode.next;
        secondNode.next.next = firstNode.next.next;
        firstNode.next.next = t;
        secondNode.next = firstNode.next;
        firstNode.next = u;
        return head;
    }

    public static LinkedList reverse(LinkedList head) {
        LinkedList prev = null;
        while(head!=null) {
            LinkedList next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    public static int length(LinkedList head) {
        int l = 0;
        LinkedList temp = head;
        while(temp!=null) {
            temp = temp.next;
            l++;
        }
        return l;
    }
//    Adding Node
    public static LinkedList add(LinkedList head, LinkedList node, int pos) {
        if(head == null) {
            head = node;
            return head;
        }
        if(pos == 0) {
            return addToStart(head, node);
        }else if(pos == -1) {
            return addToEnd(head, node);
        }
        return addAt(head, node, pos);
    }
    private static LinkedList addAt(LinkedList head, LinkedList node, int pos) {
        LinkedList temp = head;
        while(pos>1 && temp.next!=null) {
            temp = temp.next;
            pos--;
        }
        node.next = temp.next;
        temp.next = node;
        return head;
    }
    private static LinkedList addToEnd(LinkedList head, LinkedList node) {
        LinkedList temp = head;
        while (temp.next!=null) {
            temp = temp.next;
        }
        temp.next = node;
        return head;
    }
    private static LinkedList addToStart(LinkedList head, LinkedList node) {
        node.next = head;
        head = node;
        return head;
    }

//    Deleting Node
    public static LinkedList delete(LinkedList head, int key) {
        LinkedList temp = head;

        if(temp.data == key) {
            head = head.next;
            return head;
        }

        int flag = 0;
        while (temp != null) {
            if(temp.next!=null && temp.next.data == key) {
                flag = 1;
                break;
            }
            temp = temp.next;
        }

        if(flag != 1) {
            return head;
        }

        temp.next = temp.next.next;

        return head;
    }
}