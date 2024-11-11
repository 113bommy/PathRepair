n, m = map(int, input().split())
k = list(map(int, input().split()))
k.sort()
c = 0
for i in range(m):
    if k[i] >= 0:
        break
    c += k[i]
print(c)