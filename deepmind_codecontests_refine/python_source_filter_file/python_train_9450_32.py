n, k = map(int, input().split())

num = list(map(int, input().split()))
t = [-1] * n
count = 0
s = 1

while t[s - 1] == -1:
  if count == k:
    break

  t[s - 1] = count
  count += 1
  s = num[s - 1]
else:
  z = (k - t[s - 1]) % (count - t[s - 1])
  s = t.index(t[s - 1] + z + 1)
print(s)
