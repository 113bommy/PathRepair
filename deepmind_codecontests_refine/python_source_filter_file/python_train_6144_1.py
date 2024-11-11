# -*- coding: utf-8 -*-
"""
Created on Sat May 19 19:34:44 2018
ALDS1_7_B
@author: maezawa
"""

n = int(input())

parent = [-1 for _ in range(n)]
left = [-1 for _ in range(n)]
right = [-1 for _ in range(n)]
height = [None for _ in range(n)]
depth = [None for _ in range(n)]

def set_parent():
    global parent
    for i in range(n):
        if left[i] != -1:
            parent[left[i]] = i
        if right[i] != -1:
            parent[right[i]] = i

    
def set_depth(i, p):
    global depth
    if depth[i] != None:
        return
    depth[i] = p
    if right[i] != None:
        set_depth(right[i], p)
    if left[i] != None:
        set_depth(left[i], p+1)
       
def get_depth(i):
    global depth
    if depth[i] != None:
        return depth[i]
    d = 0
    u = i
    while parent[u] != -1:
        u = parent[u]
        d += 1
    depth[i] = d
    return d

def set_height(u):
    global height
    h1 = 0
    h2 = 0
    if right[u] != -1:
        h1 = set_height(right[u])+1
    if left[u] != -1:
        h2 = set_height(left[u])+1
    height[u] = max(h1, h2)
    return height[u]    

def get_sib(i):
    if right[parent[i]] == i:
        return left[parent[i]]
    else:
        return right[parent[i]]
    
def get_deg(i):
    deg = 0
    if right[i] != -1:
        deg += 1
    if left[i] != -1:
        deg += 1
    return deg    

def get_height(i):
    return height[i]

def preparse(i):
    if i == -1:
        return
    print('{} '.format(i), end='')
    preparse(left[i])
    preparse(right[i])
    
def inparse(i):
    if i == -1:
        return
    inparse(left[i])
    print('{} '.format(i), end='')
    preparse(right[i])
 
def postparse(i):
    if i == -1:
        return
    postparse(left[i])
    postparse(right[i])
    print('{} '.format(i), end='')

for i in range(n):
    line = list(map(int, input().split()))
    left[line[0]] = line[1]
    right[line[0]] = line[2]

set_parent()
root = parent.index(-1)
print('Preorder')
preparse(root)
print()
print('Inorder')
inparse(root)
print()
print('Postorder')
postparse(root)
print()        

