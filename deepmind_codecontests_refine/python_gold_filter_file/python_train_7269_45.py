N, Y = map(int, input().split())
ans = "-1 -1 -1"
for a in range(N+1):
  for b in range(N-a+1):
    c = N-a-b
    if a*10000+b*5000+c*1000 == Y:
      ans = "%d %d %d"%(a,b,c)
print(ans)


