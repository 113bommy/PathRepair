n = int(input())
a = list(map(int,input().split()))
h = 0
for i in range(1,n):
  if a[i] != i+1-h:
    h += 1
if h == n:
  print(n)
else:
  print(h)