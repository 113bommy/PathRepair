def main():
    n = int(input())
    l = []
    a = 0
    for b in map(int, input().split()):
        if a < b:
            l.append((a, b))
        else:
            l.append((b, a))
        a = b
    l[0] = ((0, 0))
    #l.sort()
    for i, (c, d) in enumerate(l):
        for j in range(i):
            a, b = l[j]
            if a < c < b < d:
                print('yes')
                return
    print('no')


if __name__ == '__main__':
    main()