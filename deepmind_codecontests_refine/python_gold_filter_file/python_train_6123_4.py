from collections import deque

MOD = 10**9 + 7


def main():
    N = int(input())
    adj = [set() for _ in range(N)]
    for _ in range(N-1):
        x, y = map(int, input().split())
        adj[x-1].add(y-1)
        adj[y-1].add(x-1)
    memo = [[0] * 2 for _ in range(N)]
    q = deque([(0, -1)])
    while len(q):
        cur, prev = q.pop()
        adjs = set([x for x in adj[cur] if x != prev])
        if len(adjs) == 0:
            memo[cur][0] = 1
            memo[cur][1] = 1
            continue
        rec = []
        black = 1
        white = 1
        for a in adjs:
            if memo[a][0] != 0:
                black = (black * memo[a][0]) % MOD
                white = (white * (memo[a][0] + memo[a][1])) % MOD
            else:
                rec += [(a, cur)]
        if len(rec):
            q.append((cur, prev))
            for r in rec:
                q.append(r)
        else:
            memo[cur][0] = white
            memo[cur][1] = black
    print(sum(memo[0]) % MOD)


if __name__ == "__main__":
    main()
