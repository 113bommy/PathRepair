import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(1000000000)

N, *XY = map(int,open(0).read().split())
MOD = 10**9 + 7

neighbor = [[] for _ in range(N)]
for x,y in zip(*[iter(XY)]*2):
    neighbor[x-1] += y-1
    neighbor[y-1] += x-1

parent = {0}

def dp(node):
    black_output = white_output = 1
    for child in neighbor[node]:
        if child in parent:
            continue
        else:
            parent.add(child)
            tmp_black, tmp_white = dp(child)
            black_output *= tmp_white
            white_output *= tmp_black + tmp_white
    black_output %= MOD
    white_output %= MOD
    return black_output, white_output

print(sum(dp(0)) % MOD)