n,r=map(int,input().split())
arr=list(map(int,input().split()))
arr1=[0]*n
for i in range(n):
    if(arr[i]==1):
        for j in range(i,max(i-r,-1),-1):
            arr1[j]+=1
        for j in range(i,min(i+r,n)):
            arr1[j]+=1
if(0 in arr1):
    print(-1)
else:
    count=arr.count(1)
    for i in range(n):
        if(arr[i]==1):
            flag=0
            for j in range(i,max(i-r,-1),-1):
                if(arr1[j]==1):
                    flag=1
            for j in range(i,min(i+r,n)):
                if(arr1[j]==1):
                    flag=1
            if(flag==0):
                for j in range(i,max(i-r,-1),-1):
                    arr1[j]-=1
                for j in range(i,min(i+r,n)):
                    arr1[j]-=1
                count-=1
    print(count) 

       



