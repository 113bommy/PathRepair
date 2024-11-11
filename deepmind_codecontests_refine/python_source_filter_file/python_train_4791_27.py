# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10 ** 9)
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

H=INT()
A=LIST()+[None]*(H*2)

for i in range(H):
    node=i+1
    key=A[i]
    parent=node//2
    left=node*2
    right=node*2+1
    print('node '+str(node)+': key = '+str(key)+', ', end='')
    if parent!=0:
        print('parent key = '+str(A[parent-1])+', ', end='')
    if A[left-1] is not None:
        print('left key = '+str(A[left-1])+', ', end='')
    if A[right-1] is not None:
        print('left key = '+str(A[right-1])+', ', end='')
    print('')

