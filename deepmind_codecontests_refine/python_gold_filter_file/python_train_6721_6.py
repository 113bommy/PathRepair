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

n = int(input())
s = input()
x = 0
j,k = 0,n-1
for i in range(n):
    if j<=k and s[j] == '<':
        x+=1
        j+=1
    elif j<=k and s[k] == '>':
        x+=1
        k-=1
print(x)















