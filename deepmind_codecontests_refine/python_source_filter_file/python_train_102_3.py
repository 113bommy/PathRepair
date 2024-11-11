N = int(input())
a = list(map(int, input().split()))
count = 0
for i in range(N)
  minj = i
  for j in range(i, N)
    if a[j] < a[minj]
      minj = j
  if a[i] != a[minj]
    a[minj], a[i] = a[i], a[minj]
    count += 1
print(*a)
print(count)