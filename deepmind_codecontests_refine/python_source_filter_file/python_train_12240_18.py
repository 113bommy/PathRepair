n,m,k=map(int,input().split())
loop=0
for i in range(1,n+1):
    c=m*i*2
    if k<c and c-k>1:
        for j in range(m,1,-1):
            c-=2
            if c==k or c-k==1:
                loop=1
                break
    elif k==c or c-k==1:
        j=m
        loop=1
    if loop:
        break
if k%2==0:
    print(i,j,"R")
else:
    print(i,j,"L")
        
                
    
