def main():
    n = int(input())
    d = [int(c) for c in input().split()]
    s, t = [int(c) for c in input().split()]

    if s > t:
        s, t = t, s

    cdist = d + d + d

    lim = len(d) + s - 1

    diff = t - s
    clockwise = sum(cdist[lim:lim + diff])
    cclockwise = sum(cdist[lim - n + diff + 1: lim + 1])
    print(min(clockwise, cclockwise))


if __name__ == "__main__":
    main()
