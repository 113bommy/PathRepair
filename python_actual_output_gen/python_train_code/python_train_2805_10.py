n,k=map(int,input().split())
arr=list(map(int,input().split()))
i=0
flag=False
while i<n-1:
    if arr[i]+1+i==k:
        print("Yes")
        flag=True
        break
    i=arr[i]+i+1
if flag==False:
    print("No")