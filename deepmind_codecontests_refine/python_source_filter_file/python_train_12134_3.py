n=int(input())
arr=list(map(int,input().split()))
ans=0
lmax=1
for i in range(1,n):
    if arr[i]>arr[i-1]:
        lmax+=1
        if lmax>ans:
            ans=lmax
    else:
        lmax=1
print(ans) 
    
    