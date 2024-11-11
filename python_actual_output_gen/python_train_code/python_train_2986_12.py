n=int(input())
for j in range(0,n):
    (x,y,z)=input().split()
    x=int(x)
    y=int(y)
    z=int(z)
    a=z*y+z-1
    b=x-1
    ans=(a+b-1)/b
    ans=ans+z
    print(ans)