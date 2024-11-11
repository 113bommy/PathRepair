#! /usr/bin/env python3

def main():
    _ = input()
    nums = map(int, input().split())

    nums = sorted(nums)
    has_consecutive = False
    for num, last_num in zip(nums[1:], nums):
        if num - last_num == 1:
            if has_consecutive:
                print('YES')
                return
            has_consecutive = True
        else:
            has_consecutive = False

    print('NO')

main()
