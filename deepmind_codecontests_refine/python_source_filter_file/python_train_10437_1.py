for i in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    nums = list(map(abs, nums))

    for j in range(1, n, 2):
        nums[j] *= -1
    
    print(nums)