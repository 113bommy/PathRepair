def main():
    n = int(input()) - 1
    [d01, d02, d12] = [int(input()) for _ in range(3)]
    min_distance = min(d01, d02, d12)

    if min_distance == d01 or min_distance == d02:
        print(min_distance * n)
    else:
        print(d12 * (n - 1) + min(d01, d02) if n > 0 else 0)


if __name__ == '__main__':
    main()
