def func(a,n1):
    maxi=0
    maxisum1=0
    if n1==1:
        return 0
    for i in range(n1-1):
        
        if a[i]>maxi:
            maxi+=1
        
        
        
        maxisum1+=a[i]-1    
    if a[n-1]==maxi:
        maxisum1+=a[i]-1
    else:
        maxisum1+=maxi
    return maxisum1
n,m=list(map(int,input().split()))
a=list(map(int,input().rstrip().split()))
print(func(a,n))


    