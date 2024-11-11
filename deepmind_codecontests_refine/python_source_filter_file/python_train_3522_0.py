def tcalc(station):
  time = 0
  for i in range(station-1,n-1):
    f = l[i][2]
    s = l[i][1]
    c = l[i][0]
    time = max(((time-1)//f+1)*f, s)+c
  return time
n = int(input())
l = [tuple(map(int, input().split())) for _ in range(n-1)]
for i in range(1,n):
  print(tcalc(i))