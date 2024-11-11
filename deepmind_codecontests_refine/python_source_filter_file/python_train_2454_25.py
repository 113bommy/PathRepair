def main():
    nums = []
    for i in range(3):
        nums.append(int(input()))
    print(compote(nums[0], nums[1], nums[2]))


def compote(a, b, c):
    d = 0
    while a >= 0 and b >= 2 and c >= 4:
        a -= 1
        b -= 2
        c -= 4
        d += 1
    return d * 7


if __name__ == "__main__":
    main()
