n = int(input())
arr = list(map(int,input().split()))

arr.sort()
ans = 1
i=0
c_len = 1
j = i+1
while i<n-1:
    j = max(i+1,j)
    while j<n and arr[j]-arr[i]<=5:
        j+=1
        c_len+=1
    ans = max(c_len,ans)
    i+=1
    c_len = max(1,c_len-1)

print(ans)

