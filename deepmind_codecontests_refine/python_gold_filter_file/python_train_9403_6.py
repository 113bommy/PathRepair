n, k = map(int, input().split())
l = list(map(int, input().split()))
t = l[k-1]
c = 0
for i in range(0, n):
    if l[i] >= t and l[i] > 0:
        c += 1
print(c)
