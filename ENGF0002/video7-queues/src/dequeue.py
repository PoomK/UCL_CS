from simple_node import Node

class Queue():
    def __init__(self):
        # create a new queue
        self.head = None
        self.tail = None

    def add_tail(self, value):
        # add to the queue
        n = Node(value)
        if self.head is None:
            self.head = n
        else:
            self.tail.append(n)
        self.tail = n

    def add_head(self, value):
        # add to the queue
        n = Node(value)
        if self.tail is None:
            self.tail = n
        else:
            self.head.prepend(n)
        self.head = n

    def pop_head(self):
        # remove the first queued element, and return its stored value

        # are there any items?
        if self.head is None:
            raise(ValueError("Attempt to pop from empty queue"))
        
        value = self.head.value
        self.head = self.head.next
        if self.head.next != None:
            self.head.next = None

        if self.head is None:
            # we've removed the last item
            self.tail = None

        return value

    def pop_tail(self):
        # remove the first queued element, and return its stored value

        # are there any items?
        if self.tail is None:
            raise(ValueError("Attempt to pop from empty queue"))
        
        value = self.tail.value
        self.tail = self.tail.next
        if self.tail.previous != None:
            self.tail.previous = None

        if self.tail is None:
            # we've removed the last item
            self.head = None

        return value

    def is_empty(self):
        return self.head is None

def test_queue():
    q = Queue()
    try:
        q.pop()
    except ValueError as err:
        assert("Attempt to pop from empty queue" in str(err))
    
    lst = [1,2,3,5,6,7,8,9,10]
    for item in lst:
        q.add(item)
        
    lst2 = []
    while not q.is_empty():
        lst2.append(q.pop())

    assert(lst2 == lst)
    try:
        q.pop()
    except ValueError as err:
        assert("Attempt to pop from empty queue" in str(err))

