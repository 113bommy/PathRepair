n=int(input())
i=0
d=0
while(i!=n):
    x,y,z=input().split()
    x,y,z=int(x),int(y),int(z)
    v=x+y
    if(v>=2):
        d=d+1
    else:pass
    i=i+1
print(d)
 
