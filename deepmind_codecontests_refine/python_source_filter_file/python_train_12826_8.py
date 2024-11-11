# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    n, k = rli()
    nums = []
    for i in range(1, k + 2):
        tmp = ['?']
        for j in range(1, k + 2):
            if j != i:
                tmp.append(j)
        print(' '.join(map(str, tmp)))
        nums.append(rli()[0])
    nums.sort()
    maxc = len(list(filter(lambda x: x == nums[-1], nums)))
    minc = len(list(filter(lambda x: x == nums[0], nums)))
    diff = len(nums) - max(maxc, minc)
    ans = None
    if maxc > minc:
        ans = k - diff + 1
    else:
        ans = diff
    print('!', ans)


if __name__ == '__main__':
    main()
