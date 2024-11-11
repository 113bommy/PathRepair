n=int(input())
z=10
r=1
p=1
k=0
while n>z :
    k=k+(z-r)*p
    r=r*10
    z=z*10
    p=p+1
if n%10==0 :
    print(k+(n-r)*p+p+1)
else :
    print(k+((n-r)+1)*p)
    
    
    
