def inters(x1,y1,x2,y2):
    return max(0, min(y1,y2) - max(x1,x2) + 1)

n, m, l  = map(int, input().split())
vol = [0] + list(map(int, input().split()))
vol.append(-1)

cnt_long_groups = 0
prev_is_short = True
for i in range(n+1):
    if vol[i] > l:
        if prev_is_short:
            prev_is_short = False
            cnt_long_groups += 1
    else:
        prev_is_short = True

for turn in range(m):
    instring = input().strip()
    print('got string', instring, 'hairs', vol)
    if instring == '0':
        print(cnt_long_groups)
    else:
        _, p, d  = map(int, instring.split())
        if vol[p] >l:
            continue
        vol[p] += d
        if vol[p] <= l:
            continue
        choice = (vol[p-1] <= l) + (vol[p+1] <= l)
        if  choice == 0:
            cnt_long_groups -= 1
        elif choice == 2:
            cnt_long_groups += 1
