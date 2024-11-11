n, m, k = map(int, input().split())
a = [0] + list(map(int, input().split()))
for i in range(1, max(m, n-m)+1):
    if m - i > 0 and 0 < a[m - i] < k:
        print(10 * i)
        break
    if m + i <= n and 0 < a[m + i] < k:
        print(10 * i)
        break

