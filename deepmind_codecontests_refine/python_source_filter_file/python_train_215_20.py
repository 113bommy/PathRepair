import bisect
n,s=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
tot,cnt=0,0
if s>=arr[n//2]:
    ind=bisect.bisect_left(arr,s)
    for i in range(n//2,ind):
        tot+=s-arr[i]
        cnt+=1
    if cnt==0:
        tot+=s-arr[n//2]
    print(tot)
else:
    ind=bisect.bisect_left(arr,s)
    for i in range(ind,n//2):
        tot+=arr[i]-s
        cnt+=1
    if cnt==0:
        tot+=arr[n//2]-s
    print(tot)
