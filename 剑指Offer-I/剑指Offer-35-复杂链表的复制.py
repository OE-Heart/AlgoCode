class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        hashTable = {}
        ptr = head
        while ptr:
            hashTable[ptr] = Node(ptr.val)
            ptr = ptr.next

        ptr = head
        while ptr:
            hashTable[ptr].next = hashTable.get(ptr.next)
            hashTable[ptr].random = hashTable.get(ptr.random)
            ptr = ptr.next

        return hashTable[head]