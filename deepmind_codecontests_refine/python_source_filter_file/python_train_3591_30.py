mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n,m=map(int, input().split())
if n>1 and m>1:
    print(m+1 if m<=n//2 else m-1)
else:
    print(m)