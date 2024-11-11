from sys import stdin, stdout


def row(i, n):
    return [i*2-1, 2*n+2*i-1, 2*n+2*i, i*2]

n, m = map(int, stdin.readline().strip().split())


ans = ""
i = 1
while i <= n and i*2-1 < m:
    r = row(i, n)
    for x in [1, 0, 2, 3]:
        if r[x] <= m:
            ans += str(r[x]) + " "
    i += 1

ans = ans.strip()
stdout.write(ans + "\n")

