n=int(input())
a=list(map(int,input().split()))
for i in range(0,n):
    if(a[i]%2==0):
        fe=0
        k=a[i]-1
        for j in range(i,n):
            if(k==a[j]):
                fe=1
                a[i]=a[i]-1
                a[j]=a[i]-1
                break
        if(fe==0):
            a[i]=a[i]-1
    else:
        k=a[i]+1
        for j in range(i,n):
            if(k==a[j]):
                a[j]=a[i]
                break
for i in range(0,n):
    print(a[i],end=" ")
        
            
        
    
