if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    count = 0
    m = pow(10, 9)
    for i in range(n - 1):
        potential_min = abs(nums[i + 1] - nums[i])
        if potential_min < m:
            count = 1
            m = potential_min
        elif potential_min == m:
            count += 1


    print(m, count)