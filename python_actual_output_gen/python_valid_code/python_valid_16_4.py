n=int(input())
arr=list(map(int,input().split()))
s=sum(arr)
count=0
ans=[]
for x in range(n):
    if arr[x]==(s-arr[x])//(n-1):
        count=count+1
        ans.append(x+1)
print(count)
for x in ans:
    print(x,end=" ")
print()
