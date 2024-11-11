n = int(input())
tmp = [input().split() for _ in range(n)]
p = list(map(int, input().split()))
l = [None] * n
for i, v in enumerate(p):
    l[i] = tmp[v - 1]
l[0] = min(l[0])
for i in range(1, n):
    if min(l[i]) < l[i - 1]:
        l[i] = min(l[i])
    elif max(l[i]) > l[i - 1]:
        l[i] = max(l[i])
    else:
        print('NO')
        break
else:
    print('YES')
