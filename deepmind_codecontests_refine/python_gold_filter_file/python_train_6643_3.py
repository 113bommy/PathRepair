def f():
    h, w, n = map(int, input().split())
    md = 10 ** 9 + 7
    k = [list(map(int, input().split())) for _ in range(n)] + [[h, w]]

    # 壁をマンハッタン距離順に
    k.sort(key=lambda x: x[0] + x[1])

    # 階乗と逆元とコンビネーションを事前準備
    fct = [1]
    re_fct = []
    fct_i = 1
    for i in range(1, h + w + 1):
        fct_i = fct_i * i % md
        fct += [fct_i]
    # fct_i**(md-2)が逆元re_i
    re_i = 1
    p = md - 2
    while p:
        if p & 1:
            re_i = re_i * fct_i % md
        p >>= 1
        fct_i = fct_i ** 2 % md
    for i in range(h + w, -1, -1):
        re_fct += [re_i]
        re_i = re_i * i % md
    re_fct = re_fct[::-1]
    cmb = lambda a, b: fct[a] * re_fct[b] * re_fct[a - b] % md

    # こっから本体
    dp = [0] * (n + 1)
    for i, [r, c] in enumerate(k):
        dpi = cmb(r + c - 2, r - 1) % md
        for j in range(i):
            dr, dc = r - k[j][0], c - k[j][1]
            if dr >= 0 and dc >= 0:
                dpi = (dpi - dp[j] * cmb(dr + dc, dr)) % md
        dp[i] = dpi
    print(dp[-1])


f()
