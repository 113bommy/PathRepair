def main():
    n, l, ones, j = int(input()), [], [], 0
    for i in range(n):
        degree, s = map(int, input().split())
        l.append((degree, s))
        j += degree
        if degree == 1:
            ones.append(i)
    print(j // 2)
    while ones:
        i = ones.pop()
        degree, j = l[i]
        if degree == 1:
            print(i, j)
            degree, s = l[j]
            s ^= i
            degree -= 1
            l[j] = degree, s
            if degree == 1:
                ones.append(j)


if __name__ == '__main__':
    main()
