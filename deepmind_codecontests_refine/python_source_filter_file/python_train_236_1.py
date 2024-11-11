from math import ceil,floor,log
import sys,threading
from heapq import heappush,heappop
from collections import Counter,defaultdict,deque
import bisect
input=lambda : sys.stdin.readline().strip()
c=lambda x: 10**9 if(x=="?") else int(x)
def rec(a,l,r,m,i,l1):
    print(l,r)
    if(l==r):
        l1[l]=i
        return
    if(l>r):
        return
    l1[max(m[l:r+1],key=lambda x:a[x])]=i
    rec(a,l,max(m[l:r+1],key=lambda x:a[x])-1,m,i+1,l1)
    rec(a,max(m[l:r+1],key=lambda x:a[x])+1,r,m,i+1,l1)
class node:
    def __init__(self,x,y):
        self.a=[x,y]
    def __lt__(self,b):
        return  b.a[0]<self.a[0]
    def __repr__(self):
        return str(self.a[0])+" "+str(self.a[1])
def main():
        for _ in range(int(input())):
            n=int(input())
            a=list(map(int,input().split()))
            l=[0]*n
            rec(a,0,n-1,list(range(n)),0,l)
            print(*l)

max_recur_size = 10**3*2 + 1000
max_stack_size = max_recur_size*500
sys.setrecursionlimit(max_recur_size)
threading.stack_size(max_stack_size)
thread = threading.Thread(target=main)
thread.start()