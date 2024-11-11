def main():
    [n, k] = [int(_) for _ in input().split()]
    slogan = input()

    if k != 1 and k != n:
        if k <= n - k + 1:
            for i in range(k - 1):
                print('LEFT')
            k = 0
        else:
            for i in range(n - k):
                print('RIGHT')
            k = n - 1
    else:
        k -= 1

    if k == 0:
        for i in range(n):
            print('PRINT ' + slogan[i])

            if i < n - 1:
                print('RIGHT')
    else:
        for i in range(n - 1, -1, -1):
            print('PRINT ' + slogan[i])

            if i > 0:
                print('LEFT')


if __name__ == '__main__':
    main()
