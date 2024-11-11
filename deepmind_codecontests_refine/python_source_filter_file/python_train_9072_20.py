n=int(input())
m=0
m=(n//2)+(1)
i=j=0
po=1
print(m)
while(n):
    print(i,j)
    if(po):
        j+=1
    else:
        i+=1
    po=not po
    n-=1