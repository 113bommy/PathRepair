n = int(input())
nums = list(map(int, input().split()))

first = sum(nums[:n])
last = sum(nums[-n:])

if first != last:
    print(*nums)
    quit()

for i in range(n):
    for j in range((2*n)-1, (2*n)-n, -1):
        if nums[i] != nums[j]:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            
            first = sum(nums[:n])
            last = sum(nums[-n:])
            
            if first != last:
                print(*nums)
                quit()
            else:
                tmp = nums[j]
                nums[j] = nums[i]
                nums[i] = tmp

else:
    print(-1)