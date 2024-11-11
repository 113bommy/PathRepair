n = int(input())
if n == 1:
    print(1)
    exit()
a = [list(map(int, input().split())) for i in range(n)]
s, r = [sum(ai) for ai in a], [0 in ai for ai in a].index(True)
x, y = s[r], s[(r + 1) % n]
if x >= y or not all(i == r or si == y for i, si in enumerate(s)):
    print(-1)
else:
    a[r][a[r].index(0)] = y - x
    fc = all(sum(a[i][j] for i in range(n)) for j in range(n))
    fld = sum(a[i][i] for i in range(n)) == y
    frd = sum(a[i][n - i - 1] for i in range(n)) == y
    print(y - x if fc and fld and frd else -1)