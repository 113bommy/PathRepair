import sys
stdin = sys.stdin

sys.setrecursionlimit(10 ** 7)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x) - 1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
ga, sa, ba = li()
gb, sb, bb = li()

vg1, vg2 = gb - ga, ga - gb
vs1, vs2 = sb - sa, sa - sb
vb1, vb2 = bb - ba, ba - bb

dp1 = [0]*(n+1)

for i in range(1,n+1):
    dp1[i] = max(dp1[i-1],
                  dp1[i-ga] + gb if i-ga >= 0 else 0,
                  dp1[i-sa] + sb if i-sa >= 0 else 0,
                  dp1[i-ba] + bb if i-ba >= 0 else 0)

m = max(n, dp1[n])
dp2 = [0] * (m+1)

for i in range(1, m+1):
    dp2[i] = max(dp2[i-1],
                 dp2[i-gb] + ga if i-gb >= 0 else 0,
                 dp2[i-sb] + sa if i-sb >= 0 else 0,
                 dp2[i-bb] + ba if i-bb >= 0 else 0)

print(max(m, dp2[m]))