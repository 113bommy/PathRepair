class Tree:
    def __init__(self, orders):
        self.root = None
        for order in orders:
            if len(order) == 1:
                self.inorder_print()
                self.preorder_print()
            else:
                if len(order[0]) == 4:
                    self.find(int(order[1]))
                else:
                    self.insert(int(order[1]))

    def insert(self, key):
        z = Node(key)
        y = None
        x = self.root
        while x:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y

        if not y:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def find(self, key):
        self.root.find(key)

    def inorder_print(self):
        self.root.inorder_print()
        print()

    def preorder_print(self):
        self.root.preorder_print()
        print()


class Node:
    def __init_(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

    def find(self, key):
        k = self.key
        if key == k:
            print('yes')
        elif key < k:
            if self.left:
                self.left.find(key)
            else:
                print('no')
        else:
            if self.right:
                self.right.find(key)
            else:
                print('no')

    def inorder_print(self):
        if self.left:
            self.left.inorder_print()
        print(' {}'.format(self.key), end='')
        if self.right:
            self.right.inorder_print()

    def preorder_print(self):
        print(' {}'.format(self.key), end='')
        if self.left:
            self.left.preorder_print()
        if self.right:
            self.right.preorder_print()


if __name__ == '__main__':
    import sys
    m = int(input())
    orders = [line.strip().split() for line in sys.stdin]
    Tree(orders)

