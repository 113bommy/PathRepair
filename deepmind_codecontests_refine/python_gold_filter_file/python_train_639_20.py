n, m, k = map(int, input().split())
P = sorted(list(map(int, input().split())))
P_dash = list(P)

ops = 0
disc = 0

while len(P_dash) > 0:
    s = P_dash[0]
    s_pos = s - disc
    # s_page = math.ceil(s_pos/k)
    s_page = (s_pos- 1) // k + 1
    r = s_page*k + disc
    try:
        while(P_dash[0] <= r):
            P_dash.pop(0)
            disc += 1
    except:
        pass
    ops += 1
    # print(ops, s, s_pos, s_page, r, P_dash)

print(ops)
