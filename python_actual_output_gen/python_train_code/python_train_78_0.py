n, x = map(int, input().split())

arr = sorted(list(map(int, input().split())))

c1 = abs(arr[n // 2] - x)

for i in range(n // 2, 0):
    if arr[i] > x:
        c1 += arr[i] - x

for i in range(n // 2 + 1, n):
    if arr[i] < x:
        c1 += x - arr[i]

print(c1)