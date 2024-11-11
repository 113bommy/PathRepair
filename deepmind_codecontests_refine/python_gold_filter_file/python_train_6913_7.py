n,k=map(int,input().split())
if k<n:
    k=k*10
s=0
c=k//n
r=k%n
x=""
if k==0 and n>1:
    print("No solution")
else:
    for i in range(n):
        if r>0:
            x+=str(c+1)
            r-=1
        else:
            x+=str(c)
    print(x)