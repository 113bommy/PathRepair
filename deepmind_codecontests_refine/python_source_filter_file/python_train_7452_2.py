n,m,k=list(map(int,input().split()))
if n&1:
    i=2
    flag=False
    while(i*i<=m):
        if m%i==0 and (k<=i<m or k<=m//i<m):
            flag=True
            break
        i+=1
    print("Timur") if flag else print("Marsel")
else:
    print("Marsel")
