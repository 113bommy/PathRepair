def solve():
    n=int(input())
    nums=list(map(int,input().split()))

    target=sum(nums)
    for i in range(2,target):
        if target%i==0:
            return n,[i for i in range(1,n+1)]
    
    for i in range(n):
        if nums[i]%2==1:idx=i;break
    return n-1,[i for i in range(i,n+1) if i!=idx+1]

for _ in range(int(input())):
    cur=solve()
    print(cur[0])
    print(*cur[1])