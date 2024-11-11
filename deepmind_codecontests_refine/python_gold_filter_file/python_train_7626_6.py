def take_item(p, f, s_n, a_n, s_w, a_w):
    # p:
    axe_p = min(p // a_w, a_n)
    a_n -= axe_p
    # f:
    sword_f = min (f // s_w, s_n)
    f -= sword_f * s_w
    axe_f = min(f // a_w, a_n)
    return axe_p + axe_f + sword_f


for _ in range(int(input())):
    p, f = [int(x) for x in input().split()]  # p1 + p2 cap
    s_n, a_n = [int(x) for x in input().split()]  # sword + axe num
    s_w, a_w = [int(x) for x in input().split()] # sword + axe weight

    res = 0
    if s_w > a_w:
        s_w, a_w = a_w, s_w
        s_n, a_n = a_n, s_n
    
    for i in range(min(s_n, p // s_w) + 1):
        tmp = i # took i swords
        p1 = p - i * s_w
        s_n_1 = s_n - i
        tmp += take_item(p1, f, s_n_1, a_n, s_w, a_w)
        res = max(res, tmp)
    print(res)