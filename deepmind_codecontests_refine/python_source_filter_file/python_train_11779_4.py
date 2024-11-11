x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if a<x:
 print("NO")
 exit(0)
else:
  if y<=a+b:
   if z<=a+b+c-y:
    print("YES")
    exit(0)
   else:
    print("NO")
    exit(0)
  else:
   print("NO")
   exit(0)