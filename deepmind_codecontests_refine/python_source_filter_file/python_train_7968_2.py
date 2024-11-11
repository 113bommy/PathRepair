n=int(input())
if n<3:
    print(-1)
elif n%2==0:
    print((n//2)**2-1,end=' ')
    print((n//2**2+1))
else:
    r=(n+1)//2
    print(2*r*(r-1),end=' ')
    print(r**2+(r-1)**2)