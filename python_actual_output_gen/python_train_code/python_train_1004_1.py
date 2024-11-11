def hashes(ai, phone):
    la = len(ai)
    lp = len(phone)

    pts = []
    i = 0
    while i + lp <= la:
        f = ai.find(phone, i)
        if f < 0:
            break
        pts.append(f)
        i = f+1

    last = -1
    k = 0
    for pt in pts:
        if pt > last:
            last = pt + lp
            k += 1

    return k


if __name__ == '__main__':
    ai = input()
    phone = input()
    print(hashes(ai, phone))
