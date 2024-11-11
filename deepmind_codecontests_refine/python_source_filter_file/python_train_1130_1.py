def main():
    n = int(input())
    xs = [int(c) for c in input().split()]
    l = int(input())

    xs.append(10 ** 17)
    nexts = list(range(n))
    for fr in range(n):
        p, q = fr, n
        while q - p > 1:
            m = (p + q) // 2
            if xs[m] - xs[fr] <= l:
                p = m
            else:
                q = m
        nexts[fr] = p

    doubling = [nexts]
    for _ in range(20):
        base = doubling[-1]
        nexts = [base[base_next] for base_next in base]
        doubling.append(nexts)

    def query(fr, to):
        if fr >= to:
            return 0
        p, q = 0, 20
        while q - p > 1:
            m = (p + q) // 2
            if doubling[m][fr] > to:
                q = m
            else:
                p = m

        return query(doubling[p][fr], to) + 2 ** p

    q_count = int(input())
    for _ in range(q_count):
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        a -= 1
        b -= 1

        print(query(a, b))


if __name__ == '__main__':
    main()