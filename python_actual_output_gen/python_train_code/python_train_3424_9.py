
n,k = list(map(int,input().split()))
arr = list(map(int,input().split()))

for i in range(1, len(arr)):
    arr[i]+= arr[i-1]

M = arr[k-1]
ans = 1
for i in range(k,len(arr)):
    t = arr[i] - arr[i-k]
    print(t, M)
    if t < M:
        M = t
        ans = i-k+2
    
print(ans)