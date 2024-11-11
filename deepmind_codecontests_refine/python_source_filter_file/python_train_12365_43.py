n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
for i in range(k, n):
    print("Yes" if a[k + i] > a[i] else "No")