def hcf(x, y):
   k=0
   if x * y >0:
       s = min(y,x)
       for i in range(s + 1,1,-1):
          if((x % i == 0) and (y % i == 0)):
              k = i
              break
   elif y * x ==0:
      k = max(x,y)
   else:
      k=0
   return k
a,b,n=[int(i) for i in input().split()]
for i in range(101):
    if i%2==0:
        n-=hcf(a,n)
        if n<0:
           print(1)
           break
    else:
        n-=hcf(b,n)
        if n<0:
           print(0)
           break
