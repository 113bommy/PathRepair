from collections import deque
import sys
input = sys.stdin.readline


def bellman_ford(N, adj, start):
    ans = [float("inf")] * N
    q = deque()
    q.append((start, 0, 0))
    while len(q):
        i, cost, path = q.pop()
        if cost >= ans[i]:
            continue
        ans[i] = cost
        for j in adj[i]:
            ncost = cost + adj[i][j]
            if path > N:
                ncost = -float("inf")
            q.append((j, ncost, path+1))
    return ans


def main():
    N, M, P = map(int, input().split())
    adj = [{} for _ in range(N)]
    for _ in range(M):
        A, B, C = map(int, input().split())
        if B-1 in adj[A-1]:
            adj[A-1][B-1] = min(P-C, adj[A-1][B-1])
        else:
            adj[A-1][B-1] = P-C
    costs = bellman_ford(N, adj, 0)
    ans = -costs[N-1]
    if ans < 0:
        print(0)
    elif ans == float("inf"):
        print(-1)
    else:
        print(ans)


if __name__ == "__main__":
    main()
