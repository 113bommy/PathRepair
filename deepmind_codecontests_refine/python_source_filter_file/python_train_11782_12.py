
for i in range(int(input())):
    k,n,a,b=map(int,input().split())
    if k-b*5<=0:
        print("-1")
    else:
        low,high=1,n
        ans=0
        while low<=high:
            mid=(low+high)//2
            print(low,high,n-mid)

            if k-(mid*b+(n-mid)*a)>0:
                ans=max(ans,n-mid)
                high=mid-1
            else:
                low=mid+1
        print(ans)
