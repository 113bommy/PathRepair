import sys

sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()

inf = 10**16
for _ in range(II()):
    x, y = MI()
    cc = LI()

    def move(x, y, d):
        cost = 0
        if d > 0:
            cost += cc[0]*d
        elif d < 0:
            cost += -cc[3]*d
        x -= d
        y -= d
        return x, y, cost

    def to0(x, y):
        cost = 0
        if x > 0: cost += cc[5]*x
        elif x < 0: cost += cc[2]*(-x)
        if y > 0: cost += cc[1]*y
        elif y < 0: cost += cc[4]*(-y)
        return cost

    ans = inf
    x1,y1,cur=move(x,y,x)
    cur+=to0(x1,y1)
    ans=min(ans,cur)
    x1,y1,cur=move(x,y,y)
    cur+=to0(x1,y1)
    ans=min(ans,cur)
    cur=to0(x,y)
    ans=min(ans,cur)
    print(ans)
