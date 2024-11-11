n,k=map(int,input().split())
arr=list(map(int,input().split()))
if k==n:
    print(1)
else:
    i=0
    ans=1
    min1=sum(arr[i:i+k])
    su=min1
    i=1
    while i+k<n:
        # su=sum(arr[i:i+k])
        su=su-arr[i-1]+arr[k+i-1]
        # print("prev:{} and late:{}".format(arr[i-1],arr[k+i-1]))
        # print("su:{} and i:{}".format(su,i))
        if min1>su:
            # print("ans=",i)
            # print("min1: ",min1)
            min1=su
            ans=i+1
        i+=1
    print(ans)