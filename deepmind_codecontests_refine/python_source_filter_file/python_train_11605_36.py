import sys
input = lambda:sys.stdin.readline()
MOD = 1000000007
ii = lambda: int(input())
si = lambda: input()
dgl = lambda: list(map(int, input()))
f = lambda: list(map(int, input().split()))
il = lambda: list(map(int, input().split()))
ls = lambda: list(input())
a,m=f()
c=0
while a%m!=0:
    a+=a%m
    c+=1
    if c>10**6:
        break
print("YNEOS"[a%m!=0::2])