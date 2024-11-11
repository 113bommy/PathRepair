n = int(input())
for _ in range(n):
    input()
    nums = list(map(int,input().split()))
    minn, maxx = 10000000,0
    for i in range(len(nums)):
        if i == 0:
           if nums[i] != -1 and nums[i+1] == -1:
               minn = min(minn,nums[i])
               maxx = max(maxx,nums[i])
        elif i==len(nums)-1:
            if nums[i]!=-1 and nums[i-1] == -1:
                minn = min(minn,nums[i])
                maxx = max(maxx,nums[i])
        elif nums[i] != -1 and (nums[i+1] == -1 or nums[i-1] == -1):
            minn = min(minn,nums[i])
            maxx = max(maxx,nums[i])
    if minn == 10000000:
        print(0, end=' ')
        print(1)
        continue
    rep = (minn+maxx)//2
    res = 0
    for i in range(len(nums)):
        if nums[i] == -1:
            nums[i] = rep
        if i:
            res = max(res,abs(nums[i]-nums[i-1]))

    print(res,end=' ')
    print(rep)