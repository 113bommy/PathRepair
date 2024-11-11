import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

class Top2:
    def __init__(self,x=-1,y=-1):
        if x<y:x,y=y,x
        self.val=[x,y]
        self.s=x+y

    def __add__(self, other):
        i=j=0
        self.val=sorted(self.val+other.val,reverse=True)[:2]
        self.s=sum(self.val)
        return self

n=II()
aa=LI()
dp=[Top2(a) for a in aa]

for i in range(n):
    for j in range((1<<n)-1,-1,-1):
        if j>>i&1:continue
        dp[j|1<<i]+=dp[j]

mx=-1
for j in range(1,1<<n):
    mx=max(mx,int(dp[j].s))
    print(mx)
