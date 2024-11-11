l,r = map(int,input().split())

if r-l >= 2018:
  print(0)
else:
  ans = 2019
  for i in range(l,r):
    for j in range(i+1,r+1):
      ans = min(ans,(i*j)%2019)

print(ans)
