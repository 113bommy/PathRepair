from heapq import heappop, heappush


def main():
    N, M, S = map(int, input().split())
    adj = [{} for _ in range(N)]
    amax = 0
    for _ in range(M):
        u, v, a, b = map(int, input().split())
        adj[u-1][v-1] = (a, b)
        adj[v-1][u-1] = (a, b)
        amax = max(amax, a)
    C = [0] * N
    D = [0] * N
    for i in range(N):
        C[i], D[i] = map(int, input().split())
    MAX = amax * N
    dp = [[float("inf")] * (MAX+1) for _ in range(N)]
    q = [(0, min(S, MAX), 0, -1)]
    ans = [None] * N
    remain = N
    while len(q) and remain:
        time, coin, cur, prev = heappop(q)
        if dp[cur][coin] <= time:
            continue
        if ans[cur] is None:
            ans[cur] = time
            remain -= 1
        dp[cur][coin] = time
        if coin < MAX:
            heappush(q, (time + D[cur], min(coin + C[cur], MAX), cur, cur))
        for nxt in adj[cur]:
            dcost, dtime = adj[cur][nxt]
            if nxt != prev and dcost <= coin:
                heappush(q, (time + dtime, coin - dcost, nxt, cur))
    for i in range(1, N):
        print(ans[i])


if __name__ == "__main__":
    main()
