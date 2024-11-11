def get_ints(string):
    return list(map(int, string.split()))


def get_input():
    a = get_ints(input())
    return a


def main():
    n, h, k = get_ints(input())
    xs = get_ints(input())
    res = 0
    hh = 0
    for x in xs:
        if hh + x <= h:
            hh += x
        else:
            res += hh // k if hh > k else 1
            hh = hh % k if hh > k else 0

            if hh + x > h:
                res += 1
                hh = x
            else:
                hh += x
        # print(hh, res)
    res += hh // k if hh % k == 0 else hh // k + 1

    print(res)

if __name__ == '__main__':
    main()
