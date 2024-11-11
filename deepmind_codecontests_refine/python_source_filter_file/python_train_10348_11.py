import sys,math
sys.setrecursionlimit(10**8)
'''
def fun():
    for i in range(16):
        for j in range(4):
            if i&(1<<j):
                print(j,end='')
        print()
import binarytree
from collections import deque
bst = binarytree.tree(height=4,is_perfect=True)
print(bst)
def s(bst):
    if bst:
        bst.left,bst.right = bst.right,bst.left
        s(bst.right)
        s(bst.left)
s(bst)
print(bst)
'''
n,m = map(int,input().split())
print(n+m-1)
for i in range(1,m+1):
    print(1,i)
for i in range(2,m+1):
    print(i,1)
