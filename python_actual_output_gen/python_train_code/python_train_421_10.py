n = int(input())
a = list(map(int, input().split()))

b = sorted(a)

l = 0
r = 0

for i in range(n):
  if a[i] != b[i]:
    l = i
    break

for j in range(l + 1, n):
  if a[j] != b[j]:
    r = j
  
segment = a[l:r + 1]
segment.reverse()

a = segment + a[r + 1:]

if a != b:
  print('no')
else:
  print('yes')
  print(l + 1, r + 1)
