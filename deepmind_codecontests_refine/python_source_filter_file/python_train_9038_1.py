import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

N, K = map(int, input().split())
WD = tuple(tuple(map(int, input().split())) for _ in range(N))

l = 1
r = 2 * 10 ** 18 + 100
while (r - l) > 1:
    pos = (r + l) // 2

    cnt = 0
    for w, d in WD:
        if pos < w:
            continue
        cnt += 1 + (pos - w) // d
    if cnt >= K:
        r = pos
    else:
        l = pos

print(r)