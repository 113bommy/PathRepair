class Node:
    def __init__(self, num, left,  right):
        self.id = num
        self.left = left
        self.right = right
        self.parent = -1
        self.brother = -1
        if self.left== -1 and self.right==-1:
        	self.child = 0
        elif self.left != -1 and self.right!=-1:
        	self.child = 2
        else:
        	self.child = 1
        self.depth = 0
        self.height = 0
        self.type = None

    def show_info(self):
        print('node {0}: parent = {1}, sibling = {2}, degree =  {3}, depth = {4}, height = {5}, {6}'.format(self.id, self.parent, self.brother, self.child, self.depth, self.height, self.type))

def SetNode(I_Line):
	L = list(map(int, I_Line.split()))
	num = L[0]
	left = L[1]
	right = L[2]
	node = Node(num, left, right)
	T[num] = node
	if left != -1:
		T[-1] -= left
	if right != -1:
		T[-1] -= right

def setPBD(i,p,b,d): #??????????????????
    node = T[i]
    node.parent = p
    node.brother = b
    node.depth = d
    if node.parent == -1:
        node.type = "root"
    elif node.child == 0:
        node.type = "leaf"
    else:
        node.type = "internal node"
    if node.left != -1:
        setPBD(node.left, i, node.right, node.depth + 1)
    if node.right != -1:
        setPBD(node.right, i, node.left, node.depth + 1)

def setH(i): #??????????????????
    node = T[i]
    if node.left == -1:
        leftheight = 0
    else:
        leftheight = setH(node.left) + 1
    if node.right == -1:
        rightheight = 0
    else:
        rightheight = setH(node.right) + 1
    node.height = max(leftheight, rightheight)
    return node.height

n = int(input())
T = [None] * n
T.append(int(n * (n-1)/2))
for i in range(n):
    x = input()
    SetNode(x)

root = T[-1]
setPBD(root, -1, -1, 0)
setH(root)
T.pop()
for i in T:
    i.show_info()