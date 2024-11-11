n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

arr = []
for i in range(n):
    arr.append(a[i] - b[i])

arr.sort()
ans = 0
l, r = 0, n - 1
while l < r:
    if arr[l] + arr[r] > 0:
        ans += r
        r -= 1
    else:
        l += 1

print(ans)
