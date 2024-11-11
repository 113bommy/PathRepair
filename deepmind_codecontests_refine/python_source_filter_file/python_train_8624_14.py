def main():
    N = int(input())
    S = input()
    M = [{'o': 0, 'x': 1}, {'o': 1, 'x': 0}]
    for s1, sn in [(0, 0), (0, 1), (1, 0), (1, 1)]:
        T = [s1]
        p, pp = s1, sn
        for s in S:
            pp, p = p, M[p ^ pp][s]
            T.append(p)
        if (s1, sn) == (p, pp):
            return T
    return None

T = main()
if not T:
    print(-1)
else:
    print(''.join('S' if s == 0 else 'W' for s in T))
