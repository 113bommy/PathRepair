from functools import reduce


def main():
    n, k = [int(_) for _ in input().split()]
    tabs = [int(_) for _ in input().split()]
    E = 0
    S = 0
    ee = [0] * k
    ss = [0] * k
    for i, t in enumerate(tabs):
        if t > 0:
            E += 1
            ee[i % k] += 1
        else:
            S += 1
            ss[i % k] += 1

    print(E, S)
    print(ee, ss)

    # Wrong variant!!!
    # mx = abs(E - S)
    # for e, s in zip(ee, ss):
    #     mx = max(mx, abs((E - e) - (S - s)))

    # Good variant
    mx = abs((E - ee[0]) - (S - ss[0]))
    for e, s in zip(ee, ss):
        mx = max(mx, abs((E - e) - (S - s)))

    # Also good variant
    mx2 = reduce(max,
                (abs((E - e) - (S - s)) for e, s in zip (ee, ss)),
                abs(E - S)
    )

    print(mx)
    # print(mx2)


if __name__ == '__main__':
    main()
