'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
t = int(input())
for _ in range(t):
    n,c=input().split()
    n=int(n)
    s=input().strip()
    if s==c*n:
        print(0)
        continue
    if s[-1]==c:
        print(1)
        print(n)
        continue
    if s[0:-1]==c*(n-1):
        print(1)
        print(n-1)
        continue
    for i in range(n//2,n+1):
        if s[i-1]!=c:
            print(1)
            print(i)
            break
    else:
        print(2)
        print(n, n - 1)
