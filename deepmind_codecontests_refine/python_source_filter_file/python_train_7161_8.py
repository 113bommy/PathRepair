n,t = map(int,input().split())
dish = []
for _ in range(n):
  a,b = map(int,input().split())
  dish.append([b,a])
dish.sort()
now = [0 for _ in range(t+1)]
for i in range(n):
  b,a = dish[i]
  for d in range(t)[::-1]:
    if d + a < t:
      now[d+a] = max(now[d+a],now[d]+b)
    else:
      now[-1] = max(now[-1],now[d]+b)
  #print(now)
print(now[-1])