n = int(input())
a = [int(x) for x in input().split()]
k = a[n - 1]
for i in range(1, n + 1):
    if a[n - i] != k:
        print(i)
        break
