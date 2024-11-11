t=int(input())
while t>0:
 x,y=input().split()
 t-=1
 x=int(x)
 y=int(y)
 if x==y:
     print("YES")
 elif x>3:
     print("YES")
 elif x==2 and y==3:
     print("YES")
 else:
     print("NO")