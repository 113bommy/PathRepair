n = int(input())
k = 1
for s in range(n, 1, -1):
    k += (s - 1) / s
print(k)
