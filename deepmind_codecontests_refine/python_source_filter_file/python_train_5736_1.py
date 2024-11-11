from collections import defaultdict


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    hasm = False
    d = defaultdict(int)
    d[0] = 1
    s = 0
    res = 0
    for i in range(m):
        if a[i] > m:
            s += 1
        if a[i] < m:
            s -= 1
        if a[i] == m:
            hasm = True
        if hasm:
            res += d[s] + d[s-1]
        else:
            d[s] += 1

    print(res)


if __name__ == '__main__':
    main()
