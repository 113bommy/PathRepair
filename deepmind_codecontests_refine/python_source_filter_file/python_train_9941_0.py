if __name__ == '__main__':
    data = [int(input()) for i in range(int(input()))]

    total = 1
    prev = data[0]

    for i, x in enumerate(data[1:]):
        prev += 1
        f = 1
        c = 1

        for j in range(x - 1):
            total *= prev
            prev += 1
            f *= c
            c += 1

        total //= f
        if total > 1000000007:
                total -= 1000000007


    print(total)