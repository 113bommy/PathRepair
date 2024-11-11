t=int(input())
for i in range(t):
  x,y=map(int, input().split())
  if x>y:
      print(x+y)  
  else:
      print((x+y)//2)  