mod = 10 ** 9 + 7
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
l=il()
l1=[0]*n
mx=l[-1]
for i in range(n-1, -1, -1):
    if l[i]<mx:
        l1[i]=mx-l[i]+1
    mx=max(l[i],mx)
print(*l1)