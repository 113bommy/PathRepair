n = int(input())

for i in range(n):
  x, y = map(int, input().split())
  
  if x - y > 2:
    print("YES")
  else:
    print("NO")