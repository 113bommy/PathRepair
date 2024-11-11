n = int(input())
a = sorted(map(int, input().split()))[::-1]
for x in range(1, n):
  if a[x] >= a[x-1]:
    a[x] = a[x-1] - 1
print(sum(a))
    