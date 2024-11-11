def make_array(n,m):
    a=[" " ]*(m+n+1)
    a[m-n]=0
    a[m+n]=0
    for i in range(0,n):
        a[m-i]=i
        a[m+i]=i
    a[m]=n
    return a

    
    
        



n=int(input())
for i in range(0,2*n+1):
    if i>n:
        
        print(*make_array(2*n-i,n))
    else:
        print(*make_array(i,n))
