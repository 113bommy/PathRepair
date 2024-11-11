from heapq import heappop, heappush
from math import sqrt
import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

INF = 10**15

def dijkstra(E, s, g):
    d = [INF] * len(E)
    d[0] = 0

    queue = []
    heappush(queue, (0, s))

    while queue:
        dist_v, v = heappop(queue)
        if dist_v > d[v]:
            continue
        
        for e, w in E[v]:
            tmp = d[v] + w
            if tmp < d[e]:
                d[e] = tmp
                heappush(queue, (tmp, e))
    
    return d[g]


def main():
    x_s, y_s, x_t, y_t = map(int, readline().split())
    N,*xyr = map(int, read().split())

    XYR = []
    XYR.append((x_s, y_s, 0))
    XYR.append((x_t, y_t, 0))
    for x, y, r in zip(*[iter(xyr)]*3):
        XYR.append((x, y, r))
    
    E = [[] for _ in range(N+2)]
    for i in range(N+1):
        x_i, y_i, r_i = XYR[i]
        for j in range(i+1, N+2):
            x_j, y_j, r_j = XYR[j]
            d = sqrt((x_i - x_j)**2 + (y_i - y_j)**2)
            d -= r_i + r_j
            d = max(0, d)
            E[i].append((j, d))
            E[j].append((i, d))

    ans = dijkstra(E, 0, 1)
    print(ans)


if __name__ == "__main__":
    main()
