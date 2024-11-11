from sys import stdin, stdout
inp = stdin.readline
for _ in range(int(inp())):
    n, k = map(int, inp().split())
    a, b, c, ans = [0], [0], [0], 2e5 + 5
    s = input()
    for i in range(n):
        a.append(a[-1] + (s[i] != 'RGB'[i % 3]))
        b.append(b[-1] + (s[i] != 'GBR'[i % 3]))
        c.append(c[-1] + (s[i] != 'BRG'[i % 3]))
    for i in range(n - k + 1):
        ans = min(ans, a[i + k] - a[i], b[i + k] - b[i], c[i + k]- c[i])
    stdout.write(str(ans))