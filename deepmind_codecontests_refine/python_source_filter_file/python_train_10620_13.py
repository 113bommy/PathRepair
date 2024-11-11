# Binary Search Tree
class Node:
    def __init__(self, v):
        self.value = v
        self.parent = None
        self.left = None
        self.right = None

# 木の根を引数として受け取り，データを挿入した新しい木の根を返す
def insert_(node, x):
    if node is None:
        return Node(x)
    elif x == node.value:
        return node
    elif x < node.value:
        node.left = insert(node.left, x)
    else:
        node.right = insert(node.right, x)
    return node

# 再帰を使わないパターン
def insert(node):
    global root
    y = None
    x = root
    while x is not None:
        y = x
        if node.value < x.value:
            x = x.left
        else:
            x = x.right
    node.parent = y
    if y is None:
        root = node
    elif node.value < y.value:
        y.left = node
    else:
        y.right = node

def preorder_walk(node):
    if node:
        yield node.value
        for x in preorder_walk(node.left):
            yield x
        for x in preorder_walk(node.right):
            yield x

def inorder_walk(node):
    if node:
        for x in inorder_walk(node.left):
            yield x
        yield node.value
        for x in inorder_walk(node.right):
            yield x

root = None
n = int(input())
for i in range(n):
    cmd, *val = input().split()
    if cmd == "insert":
        #root = insert(root, int(val[0]))
        insert(Node(val[0]))
    elif cmd == "print":
        print("", *inorder_walk(root))
        print("", *preorder_walk(root))
