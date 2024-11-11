n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * (len(a) - 1)
for i in range(len(a) - 1):
    b[i] = a[i + 1] - a[i] - 1
if len(a) > k:
    b.sort(reverse=True)
    print(sum(b[k - 1:]) + len(a))
else:
    print(len(a))