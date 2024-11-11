n = int(input())

for test_case in range(n):
    input()
    nums_strings = input().split(' ')
    nums = {}

    contains_2048 = False
    for s in nums_strings:
        si = int(s)
        if si == 2048:
            contains_2048 = True
            print('YES')
            break

        if si < 2048:
            if si in nums:
                nums[si] = nums[si] + 1
            else:
                nums[si] = 1

    if contains_2048:
        continue

    sorted_nums = sorted(nums.items(), key=lambda kv: kv[0], reverse=True)
    left = 2048

    for num, count in sorted_nums:
        left -= num * count
        if left == 0:
            contains_2048 = True
            print('YES')
            break

    if contains_2048:
        continue

    print('NO')


"""
6
4
1024 512 64 512
1
2048
3
64 512 2
2
4096 4
7
2048 2 2048 2048 2048 2048 2048
2
2048 4096

"""