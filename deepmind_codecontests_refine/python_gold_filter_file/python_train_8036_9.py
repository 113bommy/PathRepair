import collections


def gcd(a, b):
    while a > 0 and b > 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b


if __name__ == "__main__":

    for T in range(int(input())):
        r, b, k = map(int, input().split())

        g = gcd(r, b)

        r //= g
        b //= g

        mx, mn = max(r, b), min(r, b)

        if mn == mx == 1:
            print("OBEY")
        elif mn == 1:
            if mx - 1 >= k:
                print("REBEL")
            else:
                print("OBEY")
        else:
            cnt = mx // mn
            if mx % mn == 1:
                if cnt >= k:
                    print("REBEL")
                else:
                    print("OBEY")
            else:
                if cnt + 1 >= k:
                    print("REBEL")
                else:
                    print("OBEY")