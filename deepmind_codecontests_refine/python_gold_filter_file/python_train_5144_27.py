n,m=map(int,input().split())
arr=[int(x) for x in input().split()]
arr.sort()
sum=0
for i in range(m):
    if arr[i]>=0:
        break
    else:
        sum+=arr[i]
print(-sum)