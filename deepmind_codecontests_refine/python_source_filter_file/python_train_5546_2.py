for t in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))

    ans = -10**10

    if n == 5:
        ans = l[0]*l[1]*l[2]*l[3]*l[4]

    elif n == 6:
        if 0 not in l:
            prod = l[0]*l[1]*l[2]*l[3]*l[4]*l[5]
            ans = max(prod/l[0], prod/l[1], prod/l[2], prod/l[3], prod/l[4], prod/l[5])

    elif n == 7:
        if 0 not in l:
            prod = l[0]*l[1]*l[2]*l[3]*l[4]*l[5]*l[6]
            ans = max(prod/l[0]/l[1], prod/l[0]/l[2], prod/l[0]/l[3], prod/l[0]/l[4], prod/l[0]/l[5], prod/l[0]/l[6],
                      prod/l[1]/l[2], prod/l[1]/l[3], prod/l[1]/l[4], prod/l[1]/l[5], prod/l[1]/l[6],
                      prod/l[2]/l[3], prod/l[2]/l[4], prod/l[2]/l[5], prod/l[2]/l[6],
                      prod/l[3]/l[4], prod/l[3]/l[5], prod/l[3]/l[6],
                      prod/l[4]/l[5], prod/l[4]/l[6],
                      prod/l[5]/l[6])

    mp = []
    mn = []

    for i in l:
        if i > 0:
                mp.append(i)
        if i < 0:
                mn.append(i)

    if 0 in l: ans = 0
    
    mp = list(sorted(mp))
    mn = list(sorted(mn))
    
    if len(mp) >= 5:
        ans = max(ans, mp[-1]*mp[-2]*mp[-3]*mp[-4]*mp[-5])
    if len(mp) >= 3 and len(mn) >= 2:
        ans = max(ans, mp[-1]*mp[-2]*mp[-3]*mn[0]*mn[1])
    if len(mp) >= 1 and len(mn) >= 4:
        ans = max(ans, mp[-1]*mn[0]*mn[1]*mn[2]*mn[3])

    if len(mp) == 0 and len(mn) >= 5:
        ans = max(ans, mn[-1]*mn[-2]*mn[-3]*mn[-4]*mn[-5])

    print(int(ans))
