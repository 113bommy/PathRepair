import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

MOD = 998244353

N = int(input())
XY = [tuple(int(x) for x in input().split()) for _ in range(N)]
XY.sort() # X ascending
X,Y = zip(*XY)
Y_rank = {x:i for i,x in enumerate(sorted(Y),1)}

def BIT_update(tree,x):
    while x <= N:
        tree[x] += 1
        x += x & (-x)

def BIT_sum(tree,x):
    ret = 0
    while x:
        ret += tree[x]
        x -= x & (-x)
    return ret

pow2 = [1]
for _ in range(N):
    pow2.append(pow2[-1] * 2 % MOD)

answer = 0
tree = [0] * (N+1)
for L,(x,y) in enumerate(XY):
    y = Y_rank[y]
    R = N - 1 - L
    D = y - 1
    U = N - 1 - D
    LD = BIT_sum(tree,y)
    BIT_update(tree,y)
    LU = L - LD
    RD = D - LD
    RU = R - RD
    # bounding box が自分自身を含むような集合を数える
    # 全体から引く
    cnt = pow2[N]
    cnt -= pow2[L]
    cnt -= pow2[R]
    cnt -= pow2[D]
    cnt -= pow2[U]
    cnt += pow2[LD]
    cnt += pow2[LU]
    cnt += pow2[RD]
    cnt += pow2[RU]
    cnt -= 1
    answer += cnt

answer %= MOD

print(answer)