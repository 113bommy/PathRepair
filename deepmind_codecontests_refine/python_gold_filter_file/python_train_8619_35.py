from bisect import bisect_left


def main():
    N, Q, *I = map(int, open(0).read().split())
    STX, D = I[:3 * N], I[3 * N:]

    E = sorted(zip(*[iter(STX)] * 3), key=lambda x: x[2])

    R = [-1] * Q
    ans = [-1] * Q

    for s, t, x in E:
        l = bisect_left(D, s - x)
        r = bisect_left(D, t - x)
        while l < r:
            if R[l] == -1:
                ans[l] = x
                R[l] = r
                l += 1
            else:
                l = R[l]

    print(*ans, sep='\n')


if __name__ == '__main__':
    main()
