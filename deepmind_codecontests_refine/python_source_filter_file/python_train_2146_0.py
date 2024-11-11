t = int(input())
a = list(map(int, input().split()))

a.sort()
n = 1
res = 0
for i in range(t - 1):
    if a[i + 1] == a[i]:
        n += 1
    else:
        res += (n * (n + 1)) // 2
        n = 1


res += (n * (n + 1)) // 2

print(res)