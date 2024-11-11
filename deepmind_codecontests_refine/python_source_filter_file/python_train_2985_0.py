mod = 1000000007
MOD = 998244353
ii = lambda :  int(input())
si = lambda :  input()
dgl = lambda : list(map(int, input()))
f = lambda :   map(int, input().split())
il = lambda :  list(map(int, input().split()))
it = lambda :  tuple(map(int, input().split()))
ls = lambda :  list(input())
n=ii()
l=il()
c=il()
mn=10**20
for i in range(1,n-1):
    lmn1=[c[j] for j in range(i-1) if l[j]<l[i]]
    lmn2=[c[j] for j in range(i+1,n) if l[j]>l[i]]
    if len(lmn1) and len(lmn2):
        mn=min(mn,min(lmn1)+min(lmn2)+c[i])
print(mn if mn!=10**20 else -1)