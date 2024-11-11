def read_ints():
    return [int(x) for x in input().rstrip().rsplit()]


if __name__ == '__main__':
    n = int(input())

    while n > 1:
        n, m, rb, cb, rd, cd = read_ints()

        dr = 1
        dc = 1

        counter = 0
        while True:
            if rb == rd or cb == cd:
                break
            counter += 1
            if rb + dr > n or rb + dr < 1:
                dr *= -1
            if cb + dc > m or cb + dc < 1:
                dc *= -1
            rb += dr
            cb += dc

        print(counter)

        n -= 1


