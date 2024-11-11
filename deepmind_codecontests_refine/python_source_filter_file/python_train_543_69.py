import math
for tt in range(int(input())):
    
    n=int(input())
    if(n==1):
        print(0)
        continue
    else:
        k=math.ceil(n/2)
        print(k)
        j=8
        ans=0
        for i in range(1,k):
            #print(i,j)
            ans=ans+(j*i)
            j=j+8
        print(ans)    
            