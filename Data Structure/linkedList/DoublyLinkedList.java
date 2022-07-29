package com.data.linkedList;

public class DoublyLinkedList {
    private DoublyLinkedList prev;
    private int data;
    private DoublyLinkedList next;

    public DoublyLinkedList(int data) {
        this.data = data;
        prev = null;
        next = null;
    }

    public static void print(DoublyLinkedList head) {
        DoublyLinkedList curr = head;
        if (curr == null) {
            System.out.println("List Empty");
        }
        while(curr != null) {
            System.out.print(curr.data+" ");
            curr = curr.next;
        }
        System.out.println("");
    }
    public static void printPrev(DoublyLinkedList head) {
        DoublyLinkedList curr = head;
        if (curr == null) {
            System.out.println("List Empty");
        }
        while(curr != null) {
            System.out.print(curr.data+" ");
            curr = curr.prev;
        }
        System.out.println("");
    }

    public static DoublyLinkedList add(DoublyLinkedList head, DoublyLinkedList node, int pos) {
        if (head == null) {
            head = node;
            return head;
        }
        if(pos == 0) {
            head.prev = node;
            node.next = head;
            head = node;
            return head;
        }
        DoublyLinkedList curr = head;
        while(curr.next!=null && pos > 1) {
            pos--;
            curr = curr.next;
        }
        DoublyLinkedList temp = curr.next;
        curr.next = node;
        node.prev = curr;
        if(temp!=null) {
            temp.prev = node;
        }
        node.next = temp;
        return head;
    }

    public static DoublyLinkedList delete(DoublyLinkedList head, int key) {
        if (head.data == key) {
            if(head.next == null) {
                return null;
            }
            head = head.next;
            head.prev = null;
            return head;
        }

        DoublyLinkedList curr = head;
        while(curr != null && curr.data!=key) {
            curr = curr.next;
        }
        if (curr == null) {
            System.out.println("Not Found");
            return head;
        }

        if (curr.next != null) {
            curr.next.prev = curr.prev;
        }
        curr.prev.next = curr.next;
        return head;
    }
}
