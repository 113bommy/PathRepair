def main():
    n, k = map(int, input().split())
    if n % (10 ** k) == 0:
        print(n)
        return
    b2, b5 = 0, 0
    x = n
    while x % 2 == 0:
        x = x // 2
        b2 += 1
    x = n
    while x % 5 == 0:
        x = x // 5
        b5 += 1
    print(b2, b5)
    k -= min(b2, b5)
    if b2 > b5:
        if b2 - b5 > k:
            print(n * 5 ** k)
        else:
            print(n * 5 ** (b2 - b5) * 10 ** (k - b2 + b5))
    else:
        if b5 - b2 > k:
            print(n * 2 ** k)
        else:
            print(n * 2 ** (b5 - b2) * 10 ** (k - b5 + b2))

main()
