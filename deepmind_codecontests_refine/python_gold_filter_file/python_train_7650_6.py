MOD = 1000000007
MOD2 = 998244353
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
l=[]
for i in range(2,10**3+1):
    fg=0
    for j in range(2,i):
        if i%j==0:
            fg=1
            break
    if fg==0:
        l.append(i)
n=ii()
ans=[]
for i in l:
    if i>n:
        break
    x=i
    while x<=n:
        ans.append(x)
        x*=i
print(len(ans))
print(*ans)