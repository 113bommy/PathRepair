cnt = lambda s, i: s.count(i)
ii = lambda: int(input())
si = lambda : input()
f = lambda : map(int,input().split())
il = lambda : list(map(int,input().split()))
n=ii()
for i in range(n):
    n,n1,n2=f()
    print(min(n*n1,(n//2)*n2+n1))