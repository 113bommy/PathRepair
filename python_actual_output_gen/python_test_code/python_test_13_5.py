n=int(input())
arr=list(map(int,input().split()))
sume=0
arr2=[[abs(i+1-arr[i]),arr[i]] for i in range(n)]
arr2=sorted(arr2)
val=arr2[0][0]
sume=0
maxe=0
for i in range(n):
    if(arr2[i][0]==val):
        sume+=arr2[i][1]
    else:
        val=arr2[i][0]
        maxe=max(maxe,sume)
        sume=arr2[i][1]
print(max(maxe,sume))