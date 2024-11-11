n, k = map(int, input().split())
l = list(map(int, input().split()))
k = l[k-1]
i = 0

for j in range(n):
    if l[j] > 0 and l[j] > k:
        i += 1

print(i)
