n, k, m = list(map(int, input().split()))
a = sorted(list(map(int, input().split())))

sm = 0
cl = [0]
for x in a:
  sm+=x
  cl.append(sm)

def func(i):
  return (cl[-1]-cl[i]+min(k*(n-i), (m-i)))/(n-i)

mx = 0

for i in range(min(n-1, m)+1):
  res = func(i)
  if res>mx:
    mx = res

print(mx)