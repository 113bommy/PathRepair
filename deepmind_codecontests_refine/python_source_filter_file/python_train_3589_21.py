def main():
    n, m = [int(i) for i in input().split(' ')]
    boys = [0 for i in range(n)]
    girls = [0 for i in range(m)]
    nums = [int(i) for i in input().split(' ')]
    j = 1
    for i in range(nums[0]):
        boys[nums[j]] = 1
        j += 1
    nums = [int(i) for i in input().split(' ')]
    j = 1
    for i in range(nums[0]):
        girls[nums[j]] = 1
        j += 1
    j = -1
    f = 0
    while True:
        j += 1
        flag = 0
        for i in range(n):
            if boys[i] == 0:
                flag = 1
                break
        for i in range(m):
            if girls[i] == 0:
                flag = 1
                break
        if flag == 0:
            break
        a = j % n
        b = j % m
        if boys[a] == 1 or girls[b] == 1:
            boys[a] = 1
            girls[b] = 1
        if j > (m + n):
            if a == b:
                break
    if flag == 0:
        print('Yes')
    else:
        print('No')

main()
