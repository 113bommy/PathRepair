def main():
    n, l = int(input()), input().split()
    x, a = [False] * n, l[0]
    for i, b in enumerate(l):
        if a == b:
            x[i] = x[i - 1] = True
        a = b
    b = 0
    for i, a in enumerate(x):
        if a:
            if b:
                if b & 1:
                    a = l[i]
                    for j in range(i - b, i):
                        l[j] = a
                else:
                    a = l[i - b]
                    for j in range(i - b, i - b // 2 + 1):
                        l[j] = a
                    a = l[i]
                    for j in range(j, i):
                        l[j] = a
                b = 0
        else:
            b += 1
        x[i] = b
    print((max(x) + 1) // 2)
    print(' '.join(l))


if __name__ == '__main__':
    main()
