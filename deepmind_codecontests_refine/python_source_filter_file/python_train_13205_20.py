import statistics
import math

def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

n,a,b = list(map(int,input().strip().split()))
v = list(map(int,input().strip().split()))
v.sort(reverse=True)

result = 0
mean_min = statistics.mean(v[0:a])
for i in range(a,b+1):
  st_mean = statistics.mean(v[0:i])
  if mean_min == st_mean:
    v_n = v.count(v[a])
    v_r = v[0:i-1].count(v[a])
    result += combinations_count(v_n,v_r)
  else:
    break
print(mean_min)
print(result)