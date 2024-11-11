def main():
    [n, k, t] = [int(_) for _ in input().split()]

    if k <= t <= (n - k):
        print(k)
    elif t < k:
        print(t)
    else:
        print(n - t + k)


if __name__ == '__main__':
    main()
