n, t = list(map(int,input().split()))
a = list(map(int,input().split()))
for i in range(t):
  t -= 86400 - a[i]
  if t <= 0:
    print(i+1)
    break