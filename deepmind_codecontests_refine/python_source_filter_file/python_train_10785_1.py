import sys
from collections import defaultdict

def calc(a,b,p):
    return abs(a-b) + abs(p-b)

def main():
    n, k, p= map(int,sys.stdin.readline().split())
    a = list(map(int,sys.stdin.readline().split()))
    b = list(map(int,sys.stdin.readline().split()))

    a = sorted(a)
    b = sorted(b)

    v = 10**7
    for i in range(k-n+1):
        t = 0  
        for j in range(n):
            t = max(t, calc(a[j],b[j+i],p)) 
        v = min(v,t)


    print(v)



main()