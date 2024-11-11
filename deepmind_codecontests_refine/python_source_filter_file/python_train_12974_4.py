SECONDS_IN_DAY = 86400
n, t = map(int, input().split())
a = list(map(int, input().split()))

ans = -1
for i in range(len(a)):
  if t > 0:
    t = t - (SECONDS_IN_DAY - a[i])
    ans = 0 if t <= 0 else 1
    
print(ans + 1)
 

