# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n = int(input())
#a = [int(i) for i in readline().split()]
m = n
while m%2 ==0:
    m//=2
if m == 1:
    print("No")
    exit()
elif n%2:
    print("Yes")
    for i in range(2,n):
        print(i, i+1)
    print(n,1)
    print(1,n+n-1)
    for i in range(2,n,2):
        print(i+n,i+n+1)
    for i in range(2,n-2,2):
        print(i+n,i+n+3)
    print(n+1,n-1)
else:
    m=n-1
    print("Yes")
    for i in range(2,m):
        print(i, i+1)
    print(m,1)
    print(1,m+n-1)
    for i in range(2,m,2):
        print(i+n,i+n+1)
    for i in range(2,m-2,2):
        print(i+n,i+n+3)
    print(n+1,m-1)
    
    c = n^(n-2)^1
    print(c,n)
    if ((n-2)-c-1)%4==2:
        print(n-2,n+n)    
    else:
        print(n+1,n+n)    
        
    








