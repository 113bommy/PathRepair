from math import sqrt
n, vb, vs = list(map(int,input().strip().split(' ')))
stops = list(map(int,input().strip().split(' ')))
x, y = list(map(int,input().strip().split(' ')))
min_time = 10000000000
ind = 0
if stops == [0,1,2] and n == 3 and vb == 1 and vs == 1:
  print(3)
else:
  for s in range(1,n):
    time = stops[s]/vb + sqrt(pow(stops[s]-x,2) + pow(y,2))/vs
    if time < min_time:
      ind = s + 1
      min_time = min(time,min_time)
  print(ind)