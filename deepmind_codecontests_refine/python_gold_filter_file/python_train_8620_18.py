import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [list(map(int, sys.stdin.readline().split())) for _ in range(rows_number)]

def main():
    md=10**9+7
    n=int(input())
    aa=LLI(n)
    lov=[[] for _ in range(n)]
    for i,ar in enumerate(aa):
        for j,a in enumerate(ar):
            if a:lov[i].append(j)
    dp=[0]*(1<<n)
    dp[0]=1
    for s in range((1<<n)-1):
        pre=dp[s]
        if pre==0:continue
        i=bin(s).count("1")
        for j in lov[i]:
            if s>>j&1:continue
            ns=s|1<<j
            dp[ns]=(dp[ns]+pre)%md
    print(dp[-1])
    #print(dp)

main()