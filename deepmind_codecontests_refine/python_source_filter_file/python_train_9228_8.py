n = int(input())
a = [ int(x) for x in input().split()]
last = 1
y = -1
for  i in range(1,n):
     if abs(a[i] - a[i-1]) !=1:
          y  =a[i] -a[i-1]
          break
if y== -1 or y ==0:
     if y == -1:
          print("YES")
          print(int(1e9),int(1e9))
     else:
          print("NO")
else :
     f = True
     I = a[0]//y
     if a[0] % y !=0 :
          I = I+1
     J = a[0] % y
     if a[0] % y == 0 :
          J  = y
     for i in range(1,n):
          delt = a[i]-a[i-1]
          if delt == 1:
               J = J+1
          if delt == -1:
               J = J-1
          if delt ==y:
               I = I+1
          if delt ==-y:
               I =I -1
          if abs(delt)!=1 and abs(delt)!=y:
               f = False
          if I<=0 or J<=0 or J >y:
               f = False
     if f == True:
          print("YES")
          print(int(1e9), y)
     else :
          print("NO")


