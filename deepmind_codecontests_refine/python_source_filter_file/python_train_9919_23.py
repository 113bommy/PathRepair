import math
for i in range(int(input())):
   a,b=map(int,input().split())
   if a==1 or a==2:
      print(1)
   else:
      print(math.ceil((a+2)/b))
      
