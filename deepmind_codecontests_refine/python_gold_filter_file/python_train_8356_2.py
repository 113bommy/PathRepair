# from bisect import bisect_left
TC = int(input())

for tc in range(TC):
    N = int(input())
    result = None
    found = False
    # print(N)
    for a in range(N // 7 + 1):
        t = N - a * 7
        for b in range(t // 5 + 1):
            t2 = t - b * 5
            # print(t2 // 3, b, a)
            if t2 % 3 == 0:
                result = '{} {} {}'.format(t2 // 3, b, a)
                found = True
                break
        if found:
            break
    if found:
        print(result)
    else:
        print(-1)