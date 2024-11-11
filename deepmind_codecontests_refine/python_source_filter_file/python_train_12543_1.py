import sys;input=sys.stdin.readline
# from itertools import accumulate
# from decimal import *
# import math
# getcontext().prec = 50
# s = input().strip()
# n = int(input())
# lis = list(map(int,input().split()))
# x,y = map(int,input().split())
# chars = 'abcdefghijklmnopqrstuvwxyz'

# def gcd(a,b):
#     return gcd (b, a % b) if b else a
        
def solve():
    k = int(input())
    if k%2==0:
        print('NO')
        return
    
    print('YES')
    if k==1:
        print('2 1')
        print('1 2')
        return
    n = k+1
    v = 2*(n+1)
    e = n*n-1
    print(v,e)
    g = [[0 for _ in range(v)] for _ in range(v)]
    for i in range(n-1):
        g[i][i+1] = 1
    g[0][n-1] = 1
    for i in range(1,n):
        g[i][n] = 1
    diag = n-4
    for i in range(n-2):
        for j in range(i+2,i+2+diag//2):
            if j<n:
                g[i][j]=1
        for j in range(i+3+diag//2,i+3+diag):
            if j<n:
                g[i][j]=1
    
    for i in range(n+1,n+1+n-1):
        g[i][i+1] = 1
    g[n+1][n+1+n-1] = 1
    for i in range(n+1+1,n+1+n):
        g[i][n+1+n] = 1
    diag = n-4
    for i in range(n+1,n+1+n-2):
        for j in range(i+2,i+2+diag//2):
            if j<n+1+n:
                g[i][j]=1
        for j in range(i+3+diag//2,i+3+diag):
            if j<n+1+n:
                g[i][j]=1
    g[0][n+1]= 1
    for i in range(len(g)):
        for j in range(len(g[0])):
            if g[i][j] == 1:
                print(i,j)
        
    
solve()
# for _ in range(int(input())):
#     solve()    