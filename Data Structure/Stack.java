package com.data;

import java.util.ArrayList;

public class Stack<T> {
    StackNode<T> top;
    static class StackNode<T> {
        T data;
        StackNode<T> next;

        StackNode(T data) {
            this.data = data;
            next = null;
        }
    }

    boolean isEmpty() {
        return top == null;
    }

    void push(T ss) {
        StackNode<T> s = new StackNode<T>(ss);
        s.next = top;
        top = s;
    }

    T pop() {
        if(top == null)
            return null;
        T d = top.data;
        top = top.next;
        return d;
    }

    T peek() {
        if(top == null)
            return null;
        return top.data;
    }
}

class ModifiedStack<T> {
    int maxCap;
    int curr = 0;
    int cind = 0;
    ArrayList<Stack> arr = new ArrayList<>();
    ModifiedStack(int cap) {
        this.maxCap = cap;
        arr.add(new Stack());
    }

    void push(T n) {
        if(curr == maxCap) {
            arr.add(new Stack());
            cind++;
            curr = 0;
        }
        arr.get(cind).push(n);
        curr++;
    }

    T pop() {
        if(cind == 0 && curr == 0)
            return null;
        T d = (T) arr.get(cind).pop();
        curr--;

        if(curr == 0) {
            arr.remove(cind);
            cind--;
            if(cind == -1) {
                arr.clear();
                cind = 0;
                curr = 0;
            } else {
                curr = maxCap;
            }
        }

        return d;
    }

    T peek() {
        if(cind == 0 && curr == 0)
            return null;
        return (T) arr.get(cind).peek();
    }

    boolean isEmpty() {
        return cind == 0 && arr.get(cind).isEmpty();
    }
}

class MyQueue<T> {
    Stack s1[] = {new Stack<>(), new Stack<>()};

    int sNum = 0, lastOperation = 0;
    void insert(T n) {
        if(lastOperation == 0) {
            s1[0].push(n);
        } else {
            while(!s1[1].isEmpty()) {
                s1[0].push(s1[1].pop());
            }
            s1[0].push(n);
        }
        lastOperation = 0;
    }

    T remove() {
        if(lastOperation == 1) {
            return (T)s1[1].pop();
        } else {
            while(!s1[0].isEmpty()) {
                s1[1].push(s1[0].pop());
            }
        }
        lastOperation = 1;
        return (T) s1[1].pop();
    }
}

class SortedStack {
    int min;
    int len=0;
    Stack<Integer> prim = new Stack<>();
    Stack<Integer> sec = new Stack<>();

    void push(int n) {
        min = Math.min(n, min);
        prim.push(n);
        len++;
    }

    int pop() {
        return prim.pop();
    }

    boolean isEmpty() {
        return prim.isEmpty();
    }
    void sort() {
        int min = -1;
        while(prim.peek() != min) {
            int newMin = prim.peek();
            while(!prim.isEmpty() && prim.peek()>min) {
                int a = prim.pop();
                sec.push(a);
                newMin = Math.min(newMin, a);
            }
            min = newMin;
            prim.push(min);
            while(!sec.isEmpty()) {
                int a = sec.pop();
                if(a != min) {
                    prim.push(a);
                }
            }
        }
    }
}