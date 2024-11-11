def r():
    d = int(input().split()[1])
    acts = sorted(int(s) for s in input().split())
    res = 0
    m = acts[0]
    for act in acts:
        diff = act - m
        if diff % d != 0:
            return -1
        res += diff // d
    return res
r()