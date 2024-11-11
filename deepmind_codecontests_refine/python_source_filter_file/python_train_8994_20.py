def main():
    n, m = map(int, input().split())
    res = True
    if m > 2:
        l = sorted(map(int, input().split()))
        res = l[0] != 1 and l[-1] != n
        if res and m > 2:
            for a, b, c in zip(l, l[1:], l[2:]):
                if b - a == 1 == c - b:
                    res = False
                    break
    print(('NO', 'YES')[res])


if __name__ == '__main__':
    main()