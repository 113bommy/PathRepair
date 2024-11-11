n, k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]
maxx = 0
for i in range(n - k):
  j = i
  summ = 0
  while j - i + 1 < k:
    summ += a[j]
    j += 1
  while j < n:
    summ += a[j]
    maxx = max(maxx, summ / (j - i + 1))
    j += 1
print(maxx)