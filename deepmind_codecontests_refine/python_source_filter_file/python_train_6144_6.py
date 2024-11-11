def Pre(i):
    if dali[i].node != -1:
        ret = dali[i].node
        dali[i].node = -1
        order.append(ret)
    if dali[i].left != -1:
        Pre(dali[i].left)
    if dali[i].right != -1:
        Pre(dali[i].right)
def Pre2(u):
    if u == -1:
        return 
    order.append(u)
    Pre2(dali[u].left)
    Pre2(dali[u].right)
def In(i):
    if dali2[i].left != -1:
        In(dali2[i].left)
    if dali2[i].node != -1:
        
        ret = dali2[i].node
        dali2[i].node = -1
        order.append(ret)
    if dali2[i].right != -1:
        In(dali2[i].right)
def In2(u):
    if u == -1:
        return 
    In2(dali2[u].left)
    
    order.append(u)
    In2(dali2[u].right)


def Postorder(u):
    if u == -1:
        return None
    Postorder(dali3[u].left)
    Postorder(dali3[u].right)
    order.append(dali3[u].node)
    dali3[u].node = -1



    
class BiTree():
    def __init__(self, node, left, right):
        self.node = node
        self.left = left
        self.right = right


def inputdata(i):
    node, left, right = list(map(int, input().split()))
    dali[node] = BiTree(node, left, right)
    dali2[node] = BiTree(node, left, right)
    dali3[node] = BiTree(node, left, right)
def getParent(i):
    for k in range(n):
        if(dali[k].right == dali[i].node) or (dali[k].left == dali[i].node):
            dali[i].parent = dali[k].node
            return dali[i].parent
    dali[i].parent = -1
def getParent3(i):
    for k in range(n):
        if(dali3[k].right == dali3[i].node) or (dali3[k].left == dali3[i].node):
            dali3[i].parent = dali3[k].node
            return dali3[i].parent
    dali3[i].parent = -1
# Getting Root
        

n = int(input())
dali = [0] * n
dali2 = [0] * n
dali3 = [0] * n
order = []
for i in range(n):
    inputdata(i)
    """
for i in range(n):
    Pre(dali[i].node)
"""
for i in range(n):
    for j in range(n):
        if i == dali[j].left or i == dali[j].right:
            break
    if j == n-1:
        root = i
        break


order = []
for i in range(n):
    getParent(dali2[i].node)
for i in range(n):
    getParent(dali[i].node)
for i in range(n):
    getParent3(dali3[i].node)
Pre2(root)
print("Preoeder")
print(" ",end = "")
print(*order)
order = []

In2(root)
print("Inorder")
print(" ",end = "")
print(*order)

order = []
print("Postorder")
print(" ",end = "")
Postorder(root)
print(*order)







