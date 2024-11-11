def main():
    from collections import deque
    import sys
    sys.setrecursionlimit(10**7)
    input = sys.stdin.readline
    n = int(input())
    X = sorted([list(map(int,input().split())) for i in range(n)])
    mod = 998244353
    e = [[] for i in range(n)]

    def dfs(x):
        count = 1

        for i in e[x]:
            count *= dfs(i)
            count %= mod
        return count+1

    q = deque([])

    for i in range(n-1,-1,-1):
        a,b = X[i]
        while q and q[0][0] < a+b:
            e[i].append(q[0][1]) 
            q.popleft()
        q.appendleft([a,i])

    ans = 1
    for i,j in q:
        ans *= dfs(j)
        ans %= mod
    print(ans)
if __name__ == "__main__":
    main()