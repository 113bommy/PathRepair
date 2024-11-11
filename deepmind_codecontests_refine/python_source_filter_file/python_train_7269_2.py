N, Y = map(int, input().split())
 
for x in range(N+1):
  for y in range(N-x+1):
    z = N - x - y
    if 10000 * i + 5000 * j + z*1000 == Y:
      print(x,y,z)
      exit()

print(-1,-1,-1)