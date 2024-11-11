T = int(input())
for _ in range(T):
    p, f = tuple(map(int, input().split()))
    cnts, cntw = tuple(map(int, input().split()))
    s, w = tuple(map(int, input().split()))

    if s > w:
        s, w = w, s
        cnts, cntw = cntw, cnts

    ans = 0
    for i in range(cnts):
        if i * s > p:
            continue
        sf = i
        ss = min(int(f / s), cnts - i)
        left_f = p - (sf * s)
        left_s = f - (ss * s)
        wf = min(cntw, int(left_f / w))
        ws = min(int(left_s / w), cntw - wf)
        ans = max(ans, sf + ss + wf + ws)

    print(ans)