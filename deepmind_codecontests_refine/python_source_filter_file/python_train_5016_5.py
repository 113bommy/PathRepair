from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(50000)

n, k = map(int, stdin.readline().split())

p = list(map(int, stdin.readline().split()))
q = list(map(int, stdin.readline().split()))

pos = [0 for i in range(n)]

for i in range(n):
    p[i] -= 1
    q[i] -= 1
    pos[p[i]] = i

delta = [0 for i in range(n + 1)]

for i in range(n - 1):
    x = pos[q[i]]
    y = pos[q[i + 1]]
    if x > y:
        delta[y] += 1
        delta[x] -= 1

for i in range(1, n):
    delta[i] += delta[i - 1]

scc = [0 for i in range(n)]
num = 0
for i in range(n):
    if i == 0 or delta[i] != 0:
        num += 1
    scc[i] = num


if num < k:
    print('NO')
    exit(0)

s = ['a' for i in range(n)]

for i in range(n):
    x = min(26, scc[i])
    s[p[i]] = chr(96 + x)

stdout.write('YES\n')
stdout.write(''.join(s))


