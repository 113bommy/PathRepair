for t in range(int(input())):
    p, f = map(int, input().split())
    cnts, cntw = map(int, input().split())
    s, w = map(int, input().split())

    ans = 0
    for i in range(cnts+1):
        ms, fs = i, cnts-i
        ms = min(ms, p//s)
        fs = min(fs, f//s)

        rp = p-ms*s
        rf = f-fs*s

        mw, fw = rp//w, rf//w
        mw = min(mw, cntw)
        fw = min(fw, cntw-mw)
        tmp = ms+fs+mw+fw
        if tmp > ans:
            ans = tmp

    for i in range(cntw+1):
        mw, fw = i, cntw-i
        mw = min(mw, p//w)
        fw = min(fw, f//w)

        rp = p-mw*w
        rf = f-fw*w

        ms, fs = rp//s, rf//s
        ms = min(ms, cnts)
        fs = min(fs, cnts-ms)
        tmp = ms+fs+mw+fw
        if tmp > ans:
            ans = tmp

    print(ans)
