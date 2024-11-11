import math
n,a,b =map(int,input().split())
v = list(map(int,input().split()))
v = sorted(v,key=lambda x:-x)
need = v[:a]
ti = min(need)
no = need.count(ti)
try:
  ona = v[a:].count(ti)
except:
  ona = 0
if ona == 0:
  print(sum(need)/a)
  print(1)
elif no == a:
  ans = 0
  for i in range(b+1-a):
    if ona == -1:
      break
    ans += math.factorial(ona+no)/math.factorial(ona)/math.factorial(no)
    ona -= 1
    no += 1
  print(sum(need)/a)
  print(int(ans))
else:
  print(sum(need)/a)
  print(math.factorial(ona+no)/math.factorial(ona)/math.factorial(no))