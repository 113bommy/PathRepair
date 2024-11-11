n, k = map(int, input().split())
l = list(map(int, input().split()))
f = l[k-1]
i = 0

for j in range(n):
    if l[j] > 0 and l[j] >= f:
        i += 1

print(i)
