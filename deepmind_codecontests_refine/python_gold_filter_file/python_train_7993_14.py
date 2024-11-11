x,y=map(int,input().split())
if (2*y-x)%3==0 and(2*x-y)%3==0 and (2*y-x)>=0 and (2*x-y)>=0:
  
      a=(2*y-x)//3
      b=(2*x-y)//3
      numerator=1
      denominator=1
      for i in range(a):
          numerator=(numerator*(a+b-i))%(10**9+7)
          denominator=(denominator*(a-i))%(10**9+7)
      print((numerator*pow(denominator,10**9+5,10**9+7))%(10**9+7))

else:
    print(0)