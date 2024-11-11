n,k=map(int,input().split())
arr=list(map(int,input().split()))
num=arr[k-1]
flag=True
for i in range(k,n):
    if(arr[i]!=num):
        flag=False
        break

if(flag==True):
    l=0
    for i in range(k):
        if(arr[i]!=num):
            l=i
    
    print(l+1)
else:
    print("-1")