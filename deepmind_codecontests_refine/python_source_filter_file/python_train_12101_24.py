nums=[0]*451
for i in range(1,451):
    nums[i]=int((i*(i+1))/2)
#print(nums[:20])
def binserch(nums,m):
    l,r=0,len(nums)-1
    ans=450
    while l<=r:
        mid=l+(r-l)//2
        if nums[mid]>=m:
            r=mid-1
            ans=mid
        else:
            l=mid+1
    return ans
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=binserch(nums,k)
    lst=list(range(nums[a-1]+1,nums[a]+1))
    #print(lst)
    sums=binserch(lst,k)
    s=["a"]*n
    s[-a-1]="b"
    s[-sums-1]="b"
    print("".join(i for i in s))
#7
#5 1
#5 2
#5 8
#5 10
#3 1
#3 2
#20 100