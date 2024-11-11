hhmm = input().split(':')
hh = hhmm[0]
mm = hhmm[1]

if int(hh) == 23 and int(mm) > 31:
    print("00:00")
else:
    if int(hh[1]) < int(mm[0]) or hh == mm[::-1]:
        while True:
            hh = str(int(hh) + 1).zfill(2)
            reverse = hh[::-1]
            if int(reverse) < 59:
                break
    else:
        reverse = hh[::-1]
        if int(reverse) > 59 and int(reverse) > int(mm):
            while True:
                hh = str(int(hh) + 1).zfill(2)
                reverse = hh[::-1]
                if int(reverse) < 59:
                    break
    print(f'{hh}:{reverse}')
