class BinarySearchTree:
    root = None
    def insert(self, k):
        y = None
        x = self.root
        z = Node(k)
        while x:
            y = x
            if z.k < x.k:
                x = x.l
            else:
                x = x.r
        z.p = y
         
        if y == None:
            self.root = z
        else:
            if z.k < y.k:
                y.l = z
            else:
                y.r = z
                
    def find(self, x, k):
        while x != None and k != x.k:
            if k < x.k:
                x = x.l
            else:
                x = x.r
        return x
     
    def deleteNode(self, z):
        y = None
        x = None
        if z.l == None or x.r == None:
            y = z
        else:
            y = self.getSuccessor(z)
        
        if y.l != None:
            x = y.l
        else:
            x = y.r
        
        if x != None:
            x.p = y.p
        
        if y.p == None:
            self.root = x
        else:
            if y == y.p.l:
                y.p.l = x
            else:
                y.p.r = x
        
        if y != z:
            z.k = y.k

    def getSuccessor(self, x):
        if x.r != None:
            return self.getMinimum(x.r)
        y = x.p
        while y != None and x == y.r:
            x = y
            y = y.p
        return y
    
    def getMinimum(self, x):
        while x.l != None:
            x = x.l
        return x
    
    def preParse(self, u):
        if u == None:
            return
        print("", str(u.k), end = "")
        self.preParse(u.l)
        self.preParse(u.r)
 
    def inParse(self, u):
        if u == None:
            return
        self.inParse(u.l)
        print("", str(u.k), end = "")
        self.inParse(u.r)
 
class Node: 
    def __init__(self, k):
        self.k = k
        self.p = None
        self.l = None
        self.r = None
 
if __name__ == '__main__':
    n = int(input().rstrip())
    x = BinarySearchTree()
    for i in range(n):
        com = input().rstrip()
        if com.startswith("insert"):
            k = int(com.split(" ")[1])
            x.insert(k)
        elif com.startswith("find"):
            k = int(com.split(" ")[1])
            if x.find(x.root, k) != None:
                print("yes")
            else:
                print("no")
        elif com.startswith("delete"):
            k = int(com.split(" ")[1])
            x.deleteNode(x.find(x.root, k))
        else:
            x.inParse(x.root)
            print()
            x.preParse(x.root)
            print()