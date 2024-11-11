n = int(input())
f = [int(input().replace(' ', ''), 2) for i in range(n)]
p = []
for i in range(n):
    p.append([int(v) for v in input().split()])

ans = -100000000
for store in range(1, 1024):
    p_sum = 0
    for i, v in enumerate(f):
        c = v & store
        p_sum += p[i][bin(c).count('1')]
    ans = max(ans, p_sum)

print(ans)