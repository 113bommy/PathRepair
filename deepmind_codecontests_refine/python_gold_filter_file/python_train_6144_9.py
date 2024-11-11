from sys import stdin

class Node(object):
    def __init__(self, parent=None, left=None, right=None):
        self.parent = parent
        self.left = left
        self.right = right

def print_nodes(nodes, n):
    A = []
    B = []
    C = []
    def walk_tree(nodes, u):
        if u == -1:
            return
        r = nodes[u].right
        l = nodes[u].left
        nonlocal A
        A.append(u)
        walk_tree(nodes, l)
        B.append(u)
        walk_tree(nodes, r)
        C.append(u)

    for i in range(n):
        if nodes[i].parent == None:
            walk_tree(nodes, i)
            print("Preorder", end="\n ")
            print(*A, sep=" ")
            print("Inorder", end="\n ")
            print(*B, sep=" ")
            print("Postorder", end="\n ")
            print(*C, sep=" ")

def read_binary_tree(nodes, n):
    for _ in range(n):
        i = [int(i) for i in stdin.readline().strip().split()]
        nodes[i[0]].left = i[1]
        nodes[i[0]].right = i[2]
        if i[1] != -1:
            nodes[i[1]].parent = i[0]
        if i[2] != -1:
            nodes[i[2]].parent = i[0]

n = int(input())
nodes = [Node() for _ in range(n)]
read_binary_tree(nodes, n)
print_nodes(nodes, n)
