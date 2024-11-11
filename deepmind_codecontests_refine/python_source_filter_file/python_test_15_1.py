import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    s = [list(input().rstrip()) for _ in range(n)]
    for i in range(k, n):
        for j in range(m):
            if s[i][j] == ".":
                continue
            c1 = 0
            i0, j0 = i - 1, j - 1
            while 0 <= i0 < n and 0 <= j0 < m:
                if not s[i0][j0] == ".":
                    c1 += 1
                else:
                    break
                i0 -= 1
                j0 -= 1
            c2 = 0
            i0, j0 = i - 1, j + 1
            while 0 <= i0 < n and 0 <= j0 < m:
                if not s[i0][j0] == ".":
                    c2 += 1
                else:
                    break
                i0 -= 1
                j0 += 1
            c = min(c1, c2)
            if c >= k:
                s[i][j] = "@"
                i0, j0 = i - 1, j - 1
                for _ in range(c1):
                    s[i0][j0] = "@"
                    i0 -= 1
                    j0 -= 1
                i0, j0 = i - 1, j + 1
                for _ in range(c2):
                    s[i0][j0] = "@"
                    i0 -= 1
                    j0 += 1
    ans = "YES"
    for i in range(n):
        for j in range(m):
            if s[i][j] == "*":
                ans = "NO"
                break
        if ans == "NO":
            break
    print(ans)