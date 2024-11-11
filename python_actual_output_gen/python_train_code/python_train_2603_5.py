
n = int(input())

if n < 5:
    print(5 - n)
else:
    n_str = str(n)
    nums = list(n_str)
    nums[0] = str(int(nums[0]) + 1)

    for i in range(1, len(nums)):
        nums[i] = '0'

    n_str = ''
    for i in nums:
        n_str += i

    print(int(n_str) - n)
