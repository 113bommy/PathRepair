t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=[0]*n
    for i in range(n-1):
        if (a[i]&a[i+1]==a[i]):
            b[i+1]=0
        else:
            j=0
            ta=0
            for k in range(30):
                if (a[i]&(1<<j)!=0 and a[i+1]&(1<<j)==0):
                    ta+=(1<<j)
                j+=1
            b[i+1]=ta
        a[i+1]=a[i+1]^b[i+1] 
        
    for i in range(n):
        print(b[i],end=" ")
    
    print()