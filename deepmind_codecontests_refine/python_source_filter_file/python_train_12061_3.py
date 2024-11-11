def main():
    N, W = (int(i) for i in input().split())
    WV = [[int(i) for i in input().split()] for j in range(N)]
    for i in range(1, N):
        WV[i][0] -= WV[0][0]
    w_base = WV[0][0]
    WV[0][0] = 0
    V = {i: [] for i in range(4)}
    for w, v in WV:
        V[w].append(v)
    for i in range(4):
        V[i].sort(reverse=True)
    ans = 0
    from itertools import product
    for p in product(range(len(V[0])), range(len(V[1])),
                     range(len(V[2])), range(len(V[3]))):
        w_cur = w_base*p[0] + (w_base+1)*p[1] + \
            (w_base+2)*p[2] + (w_base+3)*p[3]
        if W < w_cur:
            continue
        ans = max(ans, sum(sum(V[i][:min(p[i], len(V[i]))]) for i in range(4)))
    print(ans)


if __name__ == '__main__':
    main()
