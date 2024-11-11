n = int(input())
hhmm = input()
res = list(hhmm)
hh = int(hhmm[:2])
mm = int(hhmm[3:])
if mm > 59:
    res[3] = '0'
if n == 12:
    if hh == 0:
        res[1] = '1'
    elif hh > 12:
        if int(res[1]) != '0':
            res[0] = '0'
        else:
            res[0] = '1'
else:
    if hh > 24:
        res[0] = '0'
print("".join(res))
