def main():
    n = int(input())
    seq = [int(c) for c in input().split()]
    alt = [[0, 0]]
    prev = seq[0]
    for i, e in enumerate(seq):
        if e != prev:
            alt[-1][1] += 1
        else:
            alt.append([i, i])

        prev = e

    alt = [e for e in alt if e[1] - e[0] + 1 > 2]
    steps = 0
    for a, b in alt:
        length = b - a + 1
        steps = max(steps, (length + 1) // 2 - 1)
        if length % 2 == 1:
            for i in range(a, b + 1):
                seq[i] = seq[a]
        else:
            for i in range(a, a + length // 2):
                seq[i] = seq[a]

            for i in range(a + length // 2, b + 1):
                seq[i] = seq[b]

    print(steps)
    print(*seq)


if __name__ == "__main__":
    main()
