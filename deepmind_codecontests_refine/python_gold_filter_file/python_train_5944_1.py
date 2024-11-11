def main():
    import sys
    l = int(sys.stdin.readline())
    nums = [int(x) for x in sys.stdin.readline().strip('\n').split(' ')]
    for ix, x in enumerate(nums):
        if x % 2 == 0:
            nums[ix] -= 1
    print(*nums)


main()

