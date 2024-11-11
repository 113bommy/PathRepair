n, m = map(int, input().split())
l, r = [0]*m, [0]*m
for i in range(m):
    l[i], r[i] = map(int, input().split())

print(min(r)-max(l)+1)