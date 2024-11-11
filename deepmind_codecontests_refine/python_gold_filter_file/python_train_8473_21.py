from collections import Counter


def main():
    input()
    c = Counter(map(int, input().split()))
    if c[5] or c[7] or c[2] < c[4] or c[2] + c[3] != c[1] or c[1] != c[4] + c[6]:
        print(-1)
        return
    res = [None] * c[1]
    for i in range(c[4]):
        res[i] = '1 2 4'
    for i in range(c[4], c[2]):
        res[i] = '1 2 6'
    for i in range(c[2], c[1]):
        res[i] = '1 3 6'
    print('\n'.join(res))


if __name__ == '__main__':
    main()
