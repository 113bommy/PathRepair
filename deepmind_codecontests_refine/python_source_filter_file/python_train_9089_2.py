import sys

sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LI1(): return list(map(int1, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def LLI1(rows_number): return [LI1() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
# dij = [(0, 1), (-1, 0), (0, -1), (1, 0)]
dij = [(0, 1), (-1, 0), (0, -1), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
inf = 10**16
md = 998244353
# md = 10**9+7

n = II()
aa = []
for _ in range(n):
    ca = SI().split()
    if ca[0] == "+":
        aa.append(int(ca[1]))
    else:
        aa.append(-1)

def solve(ti):
    dp = [[0]*(n+1) for _ in range(n)]
    dp[0][0] = 1
    for i in range(n-1):
        for j in range(i+1):
            pre = dp[i][j]
            if pre == 0: continue
            if i < ti:
                if aa[i] > 0:
                    if aa[i] <= aa[ti]:
                        dp[i+1][j+1] = (dp[i+1][j+1]+pre)%md
                    else:
                        dp[i+1][j] = (dp[i+1][j]+pre)%md
                else:
                    nj = max(0, j-1)
                    dp[i+1][nj] = (dp[i+1][nj]+pre)%md
                dp[i+1][j] = (dp[i+1][j]+pre)%md
            else:
                if aa[i+1] > 0:
                    if aa[i+1] <= aa[ti]:
                        dp[i+1][j+1] = (dp[i+1][j+1]+pre)%md
                    else:
                        dp[i+1][j] = (dp[i+1][j]+pre)%md
                elif j:
                    dp[i+1][j-1] = (dp[i+1][j-1]+pre)%md
                dp[i+1][j] = (pre+dp[i+1][j])%md
    # print(ti)
    # p2D(dp)
    res = 0
    for a in dp[-1]:
        res += a
        res %= md
    return res

ans = 0
for i in range(n):
    if aa[i] < 0: continue
    ans += solve(i)*aa[i]%md
    ans %= md

print(ans)
