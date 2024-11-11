t=int(input())
for i in range(t):
    a=input().split()
    n=int(a[0])
    x=int(a[1])
    nums=input().split()
    for j in range(n):
        nums[j]=int(nums[j])
    nums.sort()
    if nums[n-1]>x:
        if x in a :
            print(1)
        else:
            print(2)
    else:
        if (x%nums[n-1]==0):
            print(x//nums[n-1])
        else:
            print(x//nums[n-1]+1)
