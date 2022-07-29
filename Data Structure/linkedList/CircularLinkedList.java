package com.data.linkedList;

public class CircularLinkedList {
    public int data;
    public CircularLinkedList next;

    public CircularLinkedList(int data) {
        this.data = data;
        next = null;
    }

    public static void print(CircularLinkedList head) {
        CircularLinkedList curr = head;
        if (curr==null) {
            System.out.println("List Empty");
            return;
        }
        do{
            System.out.print(curr.data+" ");
            curr = curr.next;
        } while (curr!=head);
        System.out.println("");
    }

    public static CircularLinkedList delete(CircularLinkedList head, int key) {
        if(head.data == key) {
            CircularLinkedList curr = head;
            while(curr.next != head) {
                curr = curr.next;
            }
            head = head.next;
            if(head.next == head) {
                return null;
            }
            curr.next = head;
            return head;
        }

        CircularLinkedList curr = head;
        while(curr.next != head) {
            if(curr.next.data == key) {
                curr.next = curr.next.next;
                break;
            }
            curr = curr.next;
        }
        return head;
    }

    public static CircularLinkedList add(CircularLinkedList head, CircularLinkedList node, int pos) {
        if(head == null) {
            node.next = node;
            return node;
        }

        if(pos == 0) {
            return addToStart(head, node);
        }else if(pos == -1) {
            return addToEnd(head, node);
        }

        CircularLinkedList curr = head;
        while(curr.next!=head && pos > 1) {
            curr = curr.next;
            pos--;
        }
        CircularLinkedList temp = curr.next;
        curr.next = node;
        node.next = temp;
        return head;
    }

    private static CircularLinkedList addToStart(CircularLinkedList head, CircularLinkedList node) {
        CircularLinkedList curr = head;

        while(curr.next!=head) {
            curr = curr.next;
        }

        curr.next = node;
        node.next = head;
        head = node;
        return head;
    }

    private static CircularLinkedList addToEnd(CircularLinkedList head, CircularLinkedList node) {
        CircularLinkedList curr = head;
        while (curr.next!=head) {
            curr = curr.next;
        }
        curr.next = node;
        node.next = head;
        return head;
    }
}
