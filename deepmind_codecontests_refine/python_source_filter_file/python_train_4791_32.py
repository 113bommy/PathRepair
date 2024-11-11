# coding=utf-8
import math

class Tree():
    def __init__(self, key):
        self.root = key

class Node():
    def __init__(self, id, key):
        self.id = id
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

    def set_status(self, id, key):
        global node_list
        parent_id = math.floor(id/2)
        odd = id % 2
        self.parent = node_list[parent_id]
        if odd == 0:
            self.parent.left = self
        else:
            self.parent.right = self

def print_nodes():
    global node_list
    node_list.pop(0)
    for node in node_list:
        print("node {}: key = {}".format(node.id, node.key), end = "")
        if node.parent:
            print(", parent key = {}".format(node.parent.key), end = "")
        if node.left:
            print(", left key = {}".format(node.left.key), end = "")
        if node.right:
            print(", right key = {}".format(node.right.key), end = "")
        print(",")

n = int(input())
input_num = list(map(int, input().split()))
node_list = [None]

for i, num in enumerate(input_num):
    i = i + 1 #suffix starts from 1
    node = Node(i, num)
    node_list.append(node)

    if i == 1:
        tree = Tree(num)
    else:
        node.set_status(i, num)

print_nodes()