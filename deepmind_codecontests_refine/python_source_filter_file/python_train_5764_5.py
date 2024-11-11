def modpow(a, b, n):
    if b == 0:
        return 1
    if b == 1:
        return a % n
    tmp = modpow(a, b // 2, n) % n
    tmp = (tmp * tmp) % n
    if tmp % 2 == 1:
        return (tmp * a) % n
    else:
        return tmp


def main():
    n, m = map(int, input().split())
    ans = (modpow(3, n, m) - 1) % m
    print(ans)


if __name__ == "__main__":
    main()
