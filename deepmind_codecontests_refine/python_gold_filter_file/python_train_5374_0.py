n = int(input())
a = [int(x) for x in input().split(' ')]
b = [0] * (n + 1)
arr = []
used = [0] * (n + 1)
for i in range(0, n):
  b[a[i]] += 1
for i in range(1, n + 1):
  if b[i] == 0:
    arr.append(i)

cnt = 0
j = 0;
for i in range(0, n):
  if b[a[i]] == 1:
    continue;
  if used[a[i]] == 1:
    cnt += 1
    b[a[i]] -= 1
    a[i] = arr[j]
    j += 1
  else:
    if arr[j] < a[i]:
      cnt += 1
      b[a[i]] -= 1
      a[i] = arr[j]
      j += 1
      used[a[i]] = 1
    else:
      used[a[i]] = 1

print(cnt)
for i in range(0, n):
  print(a[i], end = " ")
