n,m,k=map(int,input().split())
arr=list(map(int,input().split()))
s=[]
res=arr[len(arr)-1]-arr[0]+1
for i in range(len(arr)-1):
    s.append(arr[i+1]-arr[i-1])
s=sorted(s)
for i in range(k - 1):
    res -= s[n - i - 2] - 1
print(res)