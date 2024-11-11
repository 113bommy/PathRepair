def main():
    n, m = list(map(int, input().split()))
    x_sum = pos_d = neg_d = 0
    for i in range(m):
        _x, _d = list(map(int, input().split()))
        x_sum += _x
        if _d > 0:
            pos_d += _d
        else:
            neg_d += _d
    big_d = small_d = 0
    big_d = (0 + (n-1)) * n / 2
    half = n // 2
    small_d = (1 + half) * half if n % 2 == 1 else half ** 2
    avg = x_sum + (big_d * pos_d + small_d * neg_d) / n
    print("{:.12f}".format(avg))
if __name__ == '__main__':
    main()
    