static class Node {
  int data;
  Node next;
  Node(int d) {
    data = d;
    next = null;
  }
}

static Node reverse(Node head) {
  if (head == null || head.next == null)
    return head;

  Node rest = reverse(head.next);
  head.next.next = head;

  head.next = null;
  return rest;
}