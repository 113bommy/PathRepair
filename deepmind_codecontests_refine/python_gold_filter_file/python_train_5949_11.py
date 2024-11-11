import sys
n,m,k=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))
arr=[]
for i in range(n):
    arr.append([a[i],i])
arr.sort(reverse=True)    
index=[]
ans=0
for i in range(m*k):
    ans+=arr[i][0]
    index.append(arr[i][1])
index.sort()
print(ans)
ans1=[]
for i in range(k-1):
    ans1.append(index[(i+1)*m-1]+1)
print(*ans1)    
    