n=int(input())
arr=list(map(int,input().split()))
arr.sort()
ans=0
pr=0
for i in range(n):
    if pr<=arr[i]:
        ans+=1 
    pr+=arr[i]
print(ans)