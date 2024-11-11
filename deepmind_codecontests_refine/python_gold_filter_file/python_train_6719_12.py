n, k = list(map(int, input().split()))
criminals = list(map(int, input().split()))

k -= 1
n -= 1
count = 0
for i in range(1, min(k, n - k) + 1):
    if criminals[k + i] and criminals[k - i]:
        count += 2

if k >= n - k:
    for i in range(k - (n - k) - 1, -1, -1):
        if criminals[i]:
            count += 1
else:
    for i in range(k + k + 1,  n + 1):
        if criminals[i]:
            count += 1

if criminals[k]:
    print(count + 1)
else:
    print(count)
