n,k,q = map(int, input().split())
a = [0]*n
for i in range(n):
  a[int(input())] += 1

for x in a:
  if k - q + x > 0:
    print("Yes")
  else:
    print("No")