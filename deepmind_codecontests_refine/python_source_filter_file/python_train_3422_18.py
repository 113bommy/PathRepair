t = ord("t")
z = ord("z")
a = ord("a")

def _decode(tv, v):
    spam = ord(v)
    if not (a <= spam <= z):
        return v

    x = t - ord(tv)
    y = spam + x

    if y > z:
        y = a + (y % z)
    elif y < a:
        y = z - (a - y - 1)

    return chr(y)

while 1:
    try:
        txt = input()
        for s in [x for x in txt.split() if 3 <= len(x) <= 4]:
            tv = s[0]
            dec_val = ''.join(list(map(lambda x:_decode(tv,x),s)))

            if (dec_val in ('this', 'the', 'that')):
                print(''.join(list(map(lambda x:_decode(tv,x),txt))))
                break
    except:
        break