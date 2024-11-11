from sys import stdin
import heapq


def main():
    n, m = map(int, stdin.readline().split())
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        x, y, w = map(int, stdin.readline().split())
        if x == y:
            continue
        adj[x].append((y, w))
        adj[y].append((x, w))
    max_val = 10 ** 10 + 1
    dist = [max_val] * (n + 1)
    dist[1] = 0
    q = []
    heapq.heappush(q, (0, 1))
    process = [False] * (n + 1)
    prev = [i for i in range(n + 1)]
    while q:
        cd, cv = heapq.heappop(q)
        if cd != dist[cv]:
            continue
        for p in adj[cv]:
            nb = p[0]
            w = p[1]
            if dist[cv] + w < dist[nb]:
                dist[nb] = dist[cv] + w
                prev[nb] = cv
                heapq.heappush(q, (dist[nb], nb))
    if dist[n] == max_val:
        print(-1)
    else:
        ans = []
        cv = n
        while prev[cv] != cv:
            ans.append(cv)
            cv = prev[cv]
        ans.append(1)
        ans.reverse()
        print(*ans)


if __name__ == '__main__':
    main()
