def main():
    import sys
    input = sys.stdin.readline
    N = int(input())
    S = [input().rstrip() for _ in range(N)]

    neg = []
    pos = []
    total = 0
    for i, s in enumerate(S):
        t = 0
        tmn = 0
        for c in s:
            if c == '(':
                t += 1
            else:
                t -= 1
            tmn = min(tmn, t)
        if t >= 0:
            pos.append((tmn, t))
        else:
            neg.append((tmn - t, -t))
        total += t

    if total != 0:
        print('No')
        return
    t = 0
    for tmn, tsm in sorted(pos, reverse=True, key=lambda x: x[0]):
        if t + tmn < 0:
            print('No')
            return
        t += tsm
    t = 0
    for tmn, tsm in sorted(neg, reverse=True, key=lambda x: x[0]):
        if t + tmn < 0:
            print('No')
            return
        t += tsm
    print('Yes')


if __name__ == '__main__':
    main()
