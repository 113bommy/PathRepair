def count(x):
    ans = 0
    for i in range(0, m, x):
        st = (2 * i + x - 1) // 2
        for j in range(i, x + i):
            ans += abs(a[j] - a[st])
    return ans


n = int(input())
data = list(map(int, input().split()))
a = []
m = 0
for i in range(n):
    if data[i] == 1:
        a.append(i)
        m += 1
k = []
for i in range(2, m + 1):
    if m % i == 0:
        k.append(i)
l, r = 0, len(k) - 1
while r - l > 4:
    m1 = l + (r - l) // 3
    m2 = r - (r - l) // 3
    if count(k[m1]) > count(k[m2]):
        l = m1
    else:
        r = m2
t = 10 ** 9
for i in range(l, r + 1):
    t = min(t, count(k[i]))
if t == 10 ** 9:
    print(-1)
else:
    print(t)
