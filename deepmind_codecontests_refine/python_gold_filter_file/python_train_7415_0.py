[n, k]=list(map(int, input().split()))
arr=list(map(int, input().split()))
par_val=(k*(2*n-k+1))//2
prev, ways = 0, 1
while(arr[prev]<n-k+1):
    prev+=1
start=prev+1
for idx in range(start, n):
    if(arr[idx]>n-k):
        ways*=(idx-prev)
        prev=idx
print(par_val, ways%998244353)