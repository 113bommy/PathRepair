import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input().rstrip())
    ans = "YES"
    if s.count("2") == 1:
        ans = "NO"
    print(ans)
    if ans == "YES":
        ans = [["="] * n for _ in range(n)]
        for i in range(n):
            ans[i][i] = "X"
        x = []
        for i in range(n):
            if s[i] == "2":
                x.append(i)
        for i in range(len(x)):
            u, v = x[i], x[(i + 1) % len(x)]
            ans[u][v] = "+"
            ans[v][u] = "-"
        for ans0 in ans:
            print("".join(ans0))