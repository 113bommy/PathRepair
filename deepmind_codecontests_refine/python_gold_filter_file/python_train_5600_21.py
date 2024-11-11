from collections import defaultdict

def main():

    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if all(a[0] == a[i] for i in range(n)):
        print(0)
        exit()

    pre = [1<<i for i in range(n)]
    bitcnt = [0]*(1<<n)
    bitcnt[1] = 1
    for i in range(1<<(n-1)):
        bitcnt[2*i] = bitcnt[i]
        bitcnt[2*i+1] = bitcnt[i]+1

    DP = [defaultdict(lambda : float("inf")) for i in range(n)]

    for i in range(n):
        DP[i][1<<i] = 0
    s = defaultdict(lambda : float("inf"))
    for i in range(n-1):
        nxt = [defaultdict(lambda : float("inf")) for i in range(n)]
        for j in range(n):
            last = a[j] if (i-j)%2 == 0 else b[j]
            for state, cost in DP[j].items():
                for to in range(n):
                    if state>>to&1:
                        continue
                    nlast = a[to] if (i+1-to)%2 == 0 else b[to]
                    if last > nlast:
                        continue
                    nstate = state|pre[to]
                    ncost = cost
                    ncost += bitcnt[state>>to]
                    if s[(nstate, nlast)] <= ncost:
                        continue
                    s[(nstate, nlast)] = ncost
                    if nxt[to][nstate] > ncost:
                        nxt[to][nstate] = ncost
        DP = nxt
    mask = (1<<n)-1
    ans = float("inf")
    for i in range(n):
        ans = min(ans, DP[i][mask])
    if ans == float("inf"):
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    main()
