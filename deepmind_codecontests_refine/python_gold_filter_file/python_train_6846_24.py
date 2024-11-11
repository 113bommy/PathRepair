def main():
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    s = set()
    b = []
    for i, x in enumerate(a, 1):
        if x not in s:
            s.add(x)
            b.append(i)

    if len(b) >= k:
        print('YES')
        print(*b[:k])
    else:
        print('NO')


if __name__ == '__main__':
    main()
