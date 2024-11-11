import sys

sys.setrecursionlimit(10**6)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def lr(xx):
    ll=[-1]*(n+1)
    rr=[-1]*(n+1)
    for i,x in enumerate(xx):
        if ll[x]==-1:ll[x]=i
        if i==n-1 or x!=xx[i+1]:rr[x]=i+1
    return ll,rr

n=II()
aa=LI()
bb=LI()
all,arr=lr(aa)
bll,brr=lr(bb)
# print(all,arr)
ca=[0]*(n+1)
cb=[0]*(n+1)
for a in aa:ca[a]+=1
for b in bb:cb[b]+=1
for i in range(n+1):
    if ca[i]+cb[i]>n:
        print("No")
        exit()
ng=[0]*(n+1)
for al,ar,bl,br in zip(all,arr,bll,brr):
    if al==-1 or bl==-1:continue
    if bl<ar:
        mn=max(0,al-br+1)
        mx=ar-bl
        ng[mn]+=1
        ng[mx]-=1
    else:
        mn=max(0,al+n-br+1)
        mx=min(n,ar+n-bl)
        ng[mn]+=1
        ng[mx]-=1
# print(ng)
for i in range(n):ng[i+1]+=ng[i]
shift=-1
for i in range(n):
    if ng[i]==0:
        shift=i
        break
ans=bb[shift:]+bb[:shift]
print("Yes")
print(*ans)
