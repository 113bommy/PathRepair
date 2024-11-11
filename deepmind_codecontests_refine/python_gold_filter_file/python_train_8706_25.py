l = [int(x) for x in input().split()]
if(1 in l):
   print("YES")
elif(l.count(2) > 1):
   print("YES")
elif(l.count(3)==3):
   print("YES")
elif(l.count(2)==1 and l.count(4)==2):
   print("YES")
elif(l.count(3)==3):
   print("YES")
   
else:
   print("NO")

