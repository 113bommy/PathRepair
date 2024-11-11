x, y = map(int, input().split())
res = 0
while(y > x) :
  x = x*2
  res += 1
print(res)