n, k = map(int, input().split())
a = list(map(int, input().split()))
cum = [0]
for i in range(n):
    cum.append(min(a[i], 0) + cum[-1])
cum2 = [0]
for i in range(n):
    cum2.append(max(a[i], 0) + cum2[-1])
SUM = sum(max(a[i], 0) for i in range(n))
l = []
for i in range(n - k + 1):
    l.append(SUM + cum[i + k] - cum[i])
    l.append(SUM - cum2[i + k] + cum2[i])
print(max(l))