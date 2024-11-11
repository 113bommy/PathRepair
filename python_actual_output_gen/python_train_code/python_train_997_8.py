n,k= map(int,input().split())
arr= list(map(int,input().split()))
last= arr[-1]
diff_ind=0
for i in range(n):
    if arr[i]!=last:
        diff_ind=i+1

if diff_ind>=k or len(set(arr[k-1:n]))!=1:
    print(-1)
else:
    print(n-diff_ind-1)
