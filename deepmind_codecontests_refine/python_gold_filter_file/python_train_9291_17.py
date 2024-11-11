# cook your dish here
from collections import deque, defaultdict
from math import sqrt, ceil, factorial, floor, inf, log2, sqrt, gcd
import bisect
import sys
import copy
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()


for _ in range(int(input())):
    n,k=get_ints()
    arr=[[0 for i in range(n)]for j in range(n)]
    i=0
    while(i!=n and k>0):
        arr[i][i]=1
        i+=1
        k-=1
    sti,stj=0,1
    stp,stq=n-1,0
    while(k>0 and stj<=n-1 and stp>0):
        i,j=sti,stj
        p,q=stp,stq
        while(k>0 and i<=n-1 and j<=n-1 ):
            arr[i][j]=1
            i+=1
            j+=1
            k-=1
        while(k>0 and p<=n-1 and q<=n-1):
            arr[p][q]=1
            p+=1
            q+=1
            k-=1
        stj+=1
        stp-=1
    a1=[]
    for i in range(len(arr)):
        a1.append(sum(arr[i]))
    a2=[]
    for j in range(n):
        sumi=0
        for i in range(n):
            sumi+=arr[i][j]
        a2.append(sumi)
    a1.sort()
    a2.sort()
    ans=((a1[n-1]-a1[0])**2)+((a2[n-1]-a2[0])**2)
    print(ans)
    for i in range(n):
        for j in range(n):
            arr[i][j]=str(arr[i][j])
    for i in range(n):
        print(''.join(arr[i]))
