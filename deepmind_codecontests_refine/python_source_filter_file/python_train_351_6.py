n = int(input())
a = [int(i) for i in input().split()]
mox = 0
b = 0
sum = 0
for i in range(n):
    sum += a[i]
    mox = max(mox, a[i])
print(max(mox, (sum + 1) // (n - 1) + 1))
