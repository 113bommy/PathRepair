def main():
    d, k, a, b, t = map(int, input().split())
    if k * (b - a) <= t:
        print(min(d, k) * a + max(0, d - k) * b)
    else:
        if d <= k:
            print(a * min(d, k))
        else:
            cnt = (d + k - 1) // k
            price1 = a * k + max(0, (cnt - 2) * (t + k * a)) + t + (d % k) * a
            price2 = a * k + max(0, (cnt - 2) * (t + k * a)) + (d % k) * b
            print(min(price1, price2))


if __name__ == '__main__':
    main()
