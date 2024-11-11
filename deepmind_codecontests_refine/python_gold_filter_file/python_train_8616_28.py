# フェルマーの小定理
def main():
    from builtins import pow

    K = int(input())
    S = input()

    m = 1000000007

    result = 0
    a = 1
    b = 1
    t = pow(26, K, m)
    u = pow(26, m - 2, m) * 25 % m
    l = len(S)
    for i in range(K + 1):
        # result += pow(26, K - i, m) * mcomb(len(S) - 1 + i, i) * pow(25, i, m)
        result += t * (a * pow(b, m - 2, m))
        result %= m
        t *= u
        t %= m
        a *= l + i
        a %= m
        b *= i + 1
        b %= m
    print(result)


main()
