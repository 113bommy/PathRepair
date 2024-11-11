n = int(input())
a = input().split()
b = a[:]
frag = 1
while frag:
  frag = 0
  for i in range(n - 1):
    if a[i][1] > a[i + 1][1]:
      a[i], a[i + 1] = a[i + 1], a[i]
      frag = 1
print(*a)
print("Stable")

for i in range(n - 1):
  minj = i
  for j in range(i, n):
    if b[j][1] < b[minj][1]:
      minj = j
  b[i], b[minj] = b[minj], b[i]
print(*b)
if a == b:
  print("Stable")
else:
  print("Not stable")
    
  