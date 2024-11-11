n = int(input())
tr = [0] * (n + 1)
for i in range(n - 1):
    u, v = map(int, input().split())
    tr[u] += 1
    tr[v] += 1
for i in range(1, n):
    if tr[i] == 2:
        print('No')
        break
else:
    print('Yes')
