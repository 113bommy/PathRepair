#BinarySearchTree
class TreeNode():
    def __init__(self):
        self.key = None
        self.parent = None
        self.left = None
        self.right = None
    def inoder(self):
        r=[]
        if self.left:
            r += self.left.inoder()
        r += [self.key]
        if self.right:
            r += self.right.inoder()
        return r

    def preoder(self):
        r=[self.key]
        if self.left:
            r += self.left.inoder()
        if self.right:
            r += self.right.inoder()
        return r

class BinaryTree():
    def __init__(self):
        self.root = None

    def insert(self, z):
        y = None
        x = self.root
        while x != None:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if y == None:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def show(self):
        x = self.root
        print(" " + " ".join(map(str, self.root.inoder())))
        print(" " + " ".join(map(str, self.root.preoder())))
 
 
n = int(input())
Tree = BinaryTree()
for i in range(n):
    L = input().split()
    if L[0] == "insert":
        Node = TreeNode()
        Node.key = int(L[1])
        Tree.insert(Node)
    else:
        Tree.show()