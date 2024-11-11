n,m,b=map(int,input().split())

p=list(map(int,input().split()))
s=list(map(int,input().split()))

k=min(p)
k1=b//k
d=k1*k
if(b>d):
   r=b-d
else:
   r=0
z=max(s)
z=k1*z

if(b>=z):
   print(b)
else:
   print(z+r)


      
   
