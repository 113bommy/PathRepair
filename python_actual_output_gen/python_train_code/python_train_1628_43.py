x, y, z = map(int, input().split())
ans = 0
if(x > y+z):
  ans = x-(y+z)+1
elif(y >= x+z):
  ans = y-(x+z)+1
elif(z >= x+y):
  ans = z-(x+y)+1
else:
  ans = 0

print(ans)
