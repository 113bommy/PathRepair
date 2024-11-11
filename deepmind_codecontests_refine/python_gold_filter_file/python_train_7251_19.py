n, s = list(map(int,input().split()))
x1, x2 = list(map(int, input().split()))
if(x1 * 60 + x2 + 1 > s + 1):
  print(0,0)
  exit()
for i in range(1, n):
  y1, y2 = list(map(int, input().split()))
  if((y1-x1) * 60 + (y2-x2) >= 2 * s + 2):
    t = x1 * 60 + x2 + s + 1
    print(t//60, t % 60)
    exit()
  x1, x2 = y1, y2
t = x1 * 60 + x2 + s + 1
print(t//60, t % 60)