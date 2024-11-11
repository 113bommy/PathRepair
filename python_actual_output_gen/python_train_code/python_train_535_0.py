n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr,reverse=True)
flag=sum(arr)%n
k=int(sum(arr)/n)
ans=0
count=0
for i in range(n):
    if count<=flag:
        ans+=abs(k+1-arr[i])
    else:
        ans+=abs(k-arr[i])
    count+=1
print(int(ans/2))