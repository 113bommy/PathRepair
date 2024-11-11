class Tree():
    def __init__(self):
        self.root = None
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
        if y == None:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def print(self):
        print('', ' '.join(map(str, self.root.inwalk())))
        print('', ' '.join(map(str, self.root.prewalk())))

    def find(self, x, k):
        while x != None and k != x.key:
            if k < x.key:
                x = x.left
            else:
                x = x.right
        return x

    def delete(self, k):
        z = self.find(tree.root, k)
        y = self.minimum(z) if z.left and z.right else z
        x = y.left if y.left else y.right

        if x:
            x.parent = y.parent
        if y.parent == None:
            self.root = x
        elif y == y.parent.left:
            y.parent.left = x
        else:
            y.parent.right = x
        if y != z:
            z.key = y.key

    def minimum(self, x):
        while x.left:
            x = x.left
        return x

class Node():
    def __init__(self, key):
        self.key = key
        self.parent = self.left = self.right = None

    def prewalk(self):
        ret = [self.key]
        if self.left:
            ret += self.left.prewalk()
        if self.right:
            ret += self.right.prewalk()
        return ret

    def inwalk(self):
        ret = []
        if self.left:
            ret += self.left.inwalk()
        ret += [self.key]
        if self.right:
            ret += self.right.inwalk()
        return ret

tree = Tree()
n = int(input())
for i in range(n):
    com = input().split()
    if com[0] == "insert":
        tree.insert(int(com[1]))
    elif com[0] == "find":
        ans = tree.find(tree.root, int(com[1]))
        if ans != None:
            print("yes")
        else:
            print("no")
    elif com[0] == "delete":
        tree.delete(int(com[1]))
    else:
        tree.print()

