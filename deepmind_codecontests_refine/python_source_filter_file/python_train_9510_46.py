import math
n=int(input())
a=list(map(int,input().split()))
min=1000000000
ans=0
a1=a.copy()
a1.sort()
for i in a1:
   if(min>i):
      min=i
      continue
   if(i == min):
      print("Still Rozdil")
      ans=1
      break
if(ans == 0):
   print(a.index(min)+1)


