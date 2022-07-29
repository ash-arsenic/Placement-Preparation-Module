package com.data;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        next = null;
    }

    void add(int data) {
        Node temp = this;
        while(temp.next != null) {
            temp = temp.next;
        }

        temp.next = new Node(data);
    }

    void print() {
        Node head = this;
        while(head != null) {
            System.out.print(head.data+" ");
            head = head.next;
        }
        System.out.println("");
    }

    void delete(int data) {
        Node head = this;
        Node prev = this;

        if(head.data == data) {
            head = head.next;
            return;
        }
        while(head!=null && head.data != data) {
            prev = head;
            head = head.next;
        }

        if(head != null)
            prev.next = head.next;
    }
}

class LinkedList {
    Node head;
    LinkedList(int data) {
        this.head = new Node(data);
    }

    static LinkedList add(LinkedList list, int data) {
        Node head = list.head;
        while(head.next != null) {
            head = head.next;
        }

        head.next = new Node(data);

        return list;
    }

    static void print(LinkedList list) {
        Node head = list.head;
        while(head!=null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println("");
    }

    static LinkedList delete(LinkedList list, int data) {
        Node head = list.head;
        Node prev = list.head;

        if(head.data == data) {
            list.head = list.head.next;
            return list;
        }
        while(head!=null && head.data != data) {
            prev = head;
            head = head.next;
        }

        if(head != null)
            prev.next = head.next;

        return list;
    }

//    Read Only area ends
    static LinkedList removeDups(LinkedList list) {
        Node curr = list.head;
        while(curr != null) {
            Node n = curr;
            while(n.next != null) {
                if(n.next.data == curr.data) {
                    n.next = n.next.next;
                } else {
                    n = n.next;
                }
            }
            curr = curr.next;
        }

        return list;
    }

    static int length(LinkedList list) {
        Node head = list.head;
        int cnt=0;
        while(head != null) {
            cnt++;
            head = head.next;
        }
        return cnt;
    }
    static int fromLast(LinkedList list, int k) {
        int len = length(list);
        Node head = list.head;
        int cnt=0;
        int ans=head.data;

        while(cnt <= (len-k)) {
            cnt++;
            ans = head.data;
            head = head.next;
        }

        return ans;
    }

    static void deleteNode(Node n) {
        if(n.next == null )
            return;
        Node nex = n.next;
        n.data = nex.data;
        n.next = nex.next;
    }

    static LinkedList partition(LinkedList list, int data) {
        Node head = list.head;
        boolean first = true;
        LinkedList l = null;
        while(head != null) {
            if(head.data < data) {
                if(first) {
                    l = new LinkedList(head.data);
                    first = false;
                } else {
                    LinkedList.add(l, head.data);
                }
            }
            head = head.next;
        }
        head = list.head;
        while(head != null) {
            if(head.data >= data) {
                if(first) {
                    l = new LinkedList(head.data);
                    first = false;
                } else {
                    LinkedList.add(l, head.data);
                }
            }
            head = head.next;
        }

        list.head = l.head;
        return l;
    }

    static LinkedList prtn(LinkedList list, int data) {
        Node head = list.head;
        Node prev = null;

        if(head.data < data) {
            prev = head;
        }

        while (head.next != null) {
            if(head.next.data < data) {
                if(prev == null) {
                    Node temp = head.next.next;
                    Node temp2 = list.head;
                    head.next.next = list.head.next;
                    list.head.next = temp;
                    list.head = head.next;
                    head.next = temp2;
                    prev = list.head;
                } else {
                    Node temp = prev.next;
                    Node temp2 = head.next.next;
                    prev.next = head.next;
                    head.next.next = temp.next;
                    head.next = temp;
                    temp.next = temp2;

                    prev = prev.next;
                }
            }
            head = head.next;
        }

        return list;
    }

    static LinkedList reverse(LinkedList list) {
        LinkedList l = new LinkedList(list.head.data);
        Node head = list.head.next;
        while(head!=null) {
            add(l, head.data);
            head = head.next;
        }

        head = l.head;
        Node prev = null;
        while(head != null) {
            Node temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        l.head = prev;
        return l;
    }
    static LinkedList sum(LinkedList l1, LinkedList l2) {
        l1 = LinkedList.reverse(l1);
        l2 = LinkedList.reverse(l2);

        Node a1 = l1.head;
        Node a2 = l2.head;
        int carry = 0;
        LinkedList ans = null;
        while(a1 != null || a2 != null) {

            int s = carry;
            if(a1 != null) {
                s += a1.data;
                a1 = a1.next;
            }
            if(a2 != null) {
                s += a2.data;
                a2 = a2.next;
            }
            if(ans == null) {
                ans = new LinkedList(s%10);
            } else {
                add(ans, s%10);
            }
            carry = s/10;
        }
        if(carry != 0)
            add(ans, carry);
        return LinkedList.reverse(ans);
    }

    static boolean pallindrome(LinkedList l1, LinkedList l2) {
        if (length(l1) != length(l2))
            return false;

        l2 = LinkedList.reverse(l2);
        Node h1 = l1.head, h2 = l2.head;
        while(h1 != null && h2 != null) {
            if(h1.data != h2.data)
                return false;
            h1 = h1.next;
            h2 = h2.next;
        }
        return true;
    }

    static Node intersection(LinkedList l1, LinkedList l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        int diff = Math.abs(len1-len2);

        Node h1 = l1.head;
        Node h2 = l2.head;

        int cnt = 0;
        if(len1 > len2) {
            while(h1 != null && cnt < diff) {
                h1 = h1.next;
                cnt++;
            }
        } else {
            while(h2 != null && cnt < diff) {
                h2 = h2.next;
                cnt++;
            }
        }

        while(h1 != null && h2 != null) {
            if(h1 == h2)
                return h1;
            h1 = h1.next;
            h2 = h2.next;
        }
        return null;
    }

    static Node loopBeginning(LinkedList l1) {
        Node runner = l1.head;
        Node curr = l1.head;

        while(runner != null && runner.next != null) {
            curr = curr.next;
            runner = runner.next.next;
            if(curr == runner)
                break;
        }

        if(runner == null || runner.next == null)
            return null;

        curr = l1.head;
        while(curr != runner) {
            curr = curr.next;
            runner = runner.next;
        }
        return curr;
    }
}

public class Main {
    public static void main(String[] args) {
	// write your code here
        SortedStack sortedStack = new SortedStack();
        sortedStack.push(6);
        sortedStack.push(8);
        sortedStack.push(1);
        sortedStack.push(9);
        sortedStack.push(4);
        sortedStack.push(5);
        sortedStack.push(3);

        sortedStack.sort();
        while(!sortedStack.isEmpty()) {
            System.out.println(sortedStack.pop());
        }

    }
}
