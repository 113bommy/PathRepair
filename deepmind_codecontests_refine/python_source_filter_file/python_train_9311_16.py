def find_longest_streak(n, nums):
    if n < 2:
        return n

    rights = [0] * n
    lefts = [0] * n
    rights[0] = 1
    lefts[n-1] = 1
    for i in range(1, n):
        if nums[i] > nums[i-1]:
            rights[i] = rights[i-1] + 1
        else:
            rights[i] = 1

    for i in range(n-2, -1, -1):
        if nums[i] < nums[i+1]:
            lefts[i] = lefts[i+1] + 1
        else:
            lefts[i] = 1

    highest = 0
    for i in range(n):
        highest = max(highest, change_value(n, nums, i, rights, lefts))
    return highest

def change_value(n, nums, index, rights, lefts):
    if index - 1 < 0:
        return lefts[index+1] + 1
    if index + 1 == n:
        return rights[index-1] + 1
    if nums[index-1] <  nums[index+1] + 1:
        return 1 + rights[index-1] + lefts[index+1]
    else:
        return max(rights[index-1], lefts[index+1]) + 1


if __name__ == '__main__':
    n = int(input())
    nums = [int(i) for i in input().split(" ")]
    print(find_longest_streak(n, nums))