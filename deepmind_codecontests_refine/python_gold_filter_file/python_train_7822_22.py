def main():
    n = int(input())
    a = list(map(int, input().split()))

    l = 0
    r = len(a) - 1

    res = []
    last = -1
    while l <= r and max(a[l], a[r]) >= last:
        if (a[l] < a[r] and a[l] >= last) or a[r] < last:
            res.append('L')
            last = a[l]
            l += 1
        else:
            res.append('R')
            last = a[r]
            r -= 1
    print(len(res))
    print(''.join(res))


if __name__ == '__main__':
    main()
