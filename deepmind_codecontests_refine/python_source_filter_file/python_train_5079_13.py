import sys, heapq
input = sys.stdin.readline
N, D, A = [int(_) for _ in input().split()]
XH = [[int(_) for _ in input().split()] for _ in range(N)]
He = [[2 * x, h, 0] for x, h in XH]
heapq.heapify(He)
now = 0
ans = 0
while He:
    x, h, t = heapq.heappop(He)
    if t:
        now -= h
    else:
        if h - D * now > 0:
            diff = (h - now - 1) // A + 1
            now += diff
            ans += diff
            heapq.heappush(He, [x + 4 * D + 1, diff, 1])
print(ans)
