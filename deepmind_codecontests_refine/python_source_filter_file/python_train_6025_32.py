n,l,*a=map(int,open(0).read().split())
ans=[]    
for i in range(1,n):
    if a[i]+a[i-1]<l:
        ans.append(i)
    else:
        for j in range(n-1,i-1,-1):
            ans.append(j)
        print("Possile")
        print(*ans,sep="\n")
        exit()
print("Impossible")