t=int(input())
for i in range(0,t):
    m,n=map(int,input().split())
    arr=list(map(int,input().strip().split()))[:m]
    x=max(arr)
    arr1=[]
    arr2=[]
    for j in range(0,m):
        y=x-arr[j]
        arr1.append(y)
    xx=max(arr1)
    for j in range(0,m):
        yy=xx-arr1[j]
        arr2.append(yy)
    if(n==0):
        print(*arr,sep=" ")
    elif(n%2==0):
        print(*arr2,sep=" ")
    else:
        print(*arr1,sep=" ")
        