package com.data;

public class Queue<T> {
    static class QueueNode<T> {
        T data;
        QueueNode<T> next;

        QueueNode(T data) {
            this.data = data;
            next = null;
        }
    }

    QueueNode<T> first;
    QueueNode<T> last;

    boolean isEmpty() {
        return first == null;
    }

    T peek() {
        if(first != null)
            return null;
        return first.data;
    }

    void add(T data) {
        QueueNode<T> qn = new QueueNode<>(data);
        if (last == null) {
            last = qn;
            first = qn;
        } else {
            last.next = qn;
            last = qn;
        }
    }

    T remove() {
        if(first == null)
            return null;

        T d = first.data;
        first = first.next;
        if(first == null)
            last = null;
        return d;
    }
}
