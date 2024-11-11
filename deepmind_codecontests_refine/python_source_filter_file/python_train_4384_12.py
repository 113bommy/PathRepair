def main():
    [w, h, k] = [int(x) for x in input().split()]
    gilded = 0

    for _ in range(k):
        if w > 0 and h > 0:
            gilded += ((w + h) * 2 - 4)
        w -= 2
        h -= 2

    print(gilded)


if __name__ == '__main__':
    main()
