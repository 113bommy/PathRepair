x=int(input())
a=1
for i in range(1,x+1):
    for j in range(1,x+1):
        if i*j>x:
            if j%i==0:
                if i//j<x:
                    print(i,j)
                    a=0
                    break
        if a==0:
            break
if a==1:
    print(-1)
        
