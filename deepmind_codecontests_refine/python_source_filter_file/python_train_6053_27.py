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
cnt1 = int(input())
cnt2 = int(input())
cnt3 = int(input())
cnt4 = int(input())
if cnt1+cnt2+cnt3+cnt4 == 0:
    print(1)
elif (cnt1*2 + cnt3 == cnt3+ cnt4*2 ) and cnt1!=0 and cnt4!=0:
    print(1)
else:
    print(0)
