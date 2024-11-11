n = int(input())
a = [int(x) for x in input().split()]
max1 = 1
min2 = 1000000
for i in range(n):
    if a[i] <= 499999:
        max1 = max(max1, a[i])
    else:
        min2 = min(min2, a[i])
print(max(max1-1, 1000000 - min2))
