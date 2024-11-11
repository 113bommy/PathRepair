import random
from sys import stdout
n,start,x=map(int,input().split())
ans=start
annnsss=-1
z=0
print("?",start)
stdout.flush()
anss,b=map(int,input().split())
if anss>=x:
   print("!",anss)
   stdout.flush()
else:
   i = 0
   while z != 10 and i!= 1000:
      i=i+1
      anns=random.randrange(1,n+1)
      print("?",anns)
      stdout.flush()
      annss,b=map(int,input().split())
      if (annss<x) and (anns<annss):
         ans=anns
         anss=annss
      if annss == x:
         print("!", x)
         stdout.flush()
         z = 10
   if z!=10:
      print("?",ans)
      stdout.flush()
      anss,b=map(int,input().split())
      while (anss<x and b!=-1):
         print("?",b)
         stdout.flush()
         anss,b=map(int,input().split())
      if anss<x:
         print("! -1")
         stdout.flush()
      else:
         print("!", anss)
         stdout.flush()
         
         
