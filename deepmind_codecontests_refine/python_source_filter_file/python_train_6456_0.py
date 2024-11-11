from io import StringIO

class BinaryTree:

    class Node:
        def __init__(self, key):
            self.key = key
            self.left = None
            self.right = None
            self.parent = None


    def __init__(self):
        self.root = None
        self.output = StringIO()

    def insert(self, key):
        if self.root is None:
            self.root = self.Node(key)
        else:
            root = self.root
            temp = None
            while True:
                temp = root
                if key > root.key:
                    root = root.right
                    if root is None:
                        temp.right = self.Node(key)
                        break
                else:
                    root = root.left
                    if root is None:
                        temp.left = self.Node(key)
                        break

    def ini_print_inorder(self):
        self.output = StringIO()
        self.print_inorder(self.root)
        return self.output.getvalue()

    def ini_print_preorder(self):
        self.output = StringIO()
        self.print_preorder(self.root)
        return self.output.getvalue()

    def print_inorder(self, node):
        if node is not None:
            self.print_inorder(node.left)
            print(node.key, end = " ", file = self.output)
            self.print_inorder(node.right)

    def print_preorder(self, node):
        if node is not None:
            print(node.key, end = " ", file = self.output)
            self.print_preorder(node.left)
            self.print_preorder(node.right)

    def test_insert(self, keys):
        for k in keys:
            self.insert(k)

    def ini_find(self, key):
        print(self.find(key))

    def find(self, key):
        root = self.root
        while root is not None:
            if key == root.key:
                return "yes"
            elif key < root.key:
                root = root.left
            else:
                root = root.right
        return "no"


length = int(input())
b = BinaryTree()
for _ in range(length):
    comm = input()
    if comm[0] == "i":
        com, num = comm.split(" ")
        b.insert(int(num))
    elif comm[0] == "p":
        print(" ", end = "")
        print((b.ini_print_inorder())[:-1])
        print(" ", end = "")
        print(b.ini_print_preorder()[:-1])
    else:
        com, num = comm.split(" ")
        b.ini_find(num)

