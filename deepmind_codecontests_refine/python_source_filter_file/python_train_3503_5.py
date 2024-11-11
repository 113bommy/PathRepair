I=lambda:int(input())
n=I()
k=I()
a=I()
b=I()

t=0
if k==1:
   print(a)
else:   
   while n>1:
     if n>=k:
        x=n%k
     else:
        x=n%k-1   
     if x!=0:
        t+=(x*a)
        n-=x
     else:
        y=n//k
        xs=n-y
        if xs*a<b:
           t+=xs*a
           n-=xs
        else:
           t+=b
           n=n//k

   print(t)            
         