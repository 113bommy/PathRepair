from collections import namedtuple

class TreeWalk:
    def __init__(self, t):
        self.t = t

    def preParse(self, u):
        if u == -1:
            return 
        print(" ", str(u), end = "")
        self.preParse(self.t[u].l)
        self.preParse(self.t[u].r)

    def inParse(self, u):
        if u == -1:
            return 
        self.inParse(self.t[u].l)
        print(" ", str(u), end = "")
        self.inParse(self.t[u].r)

    def postParse(self, u):
        if u == -1:
            return 
        self.postParse(self.t[u].l)
        self.postParse(self.t[u].r)
        print(" ", str(u), end = "")
    
if __name__ == '__main__':
    n = int(input().rstrip())
    Node = namedtuple('Node', ['p', 'l', 'r'])
    t = [Node(-1, -1, -1)] * n
    root = -1
    for i in range(n):
        v, l, r = [int(i) for i in input().rstrip().split(" ")]
        t[v] = t[v]._replace(l = l, r = r)
        if l != -1:
            t[l] = t[l]._replace(p = v)
        if r != -1:
            t[r] = t[r]._replace(p = v)
    for i in range(n):
        if (t[i].p == -1):
            root = i

    x = TreeWalk(t)
    print("Preorder")
    x.preParse(root)
    print()
    print("Inorder")
    x.inParse(root)
    print()
    print("Postorder")
    x.postParse(root)
    print()