n = int(input())
a = [int(x) for x in input().split()]
for i in range(1, n):
    k, j = a[i], i-1
    while j >= 0 and a[j] > k:
        a[j+1], j = a[j], j-1
    a[j+1] = k
    print(*a)