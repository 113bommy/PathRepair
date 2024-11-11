a,b=map(int, input().split())
a+=b
if a%2==1:
  print("IMPOSSIBLE")
else:
  print(a//2)