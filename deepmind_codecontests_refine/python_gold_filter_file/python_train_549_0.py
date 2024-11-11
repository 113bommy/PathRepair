def main():
    vp = int(input())
    vd = int(input())
    t = int(input())
    f = int(input())
    c = int(input())
    drops = 0
    mp = t * vp
    if vp >= vd:
        return 0
    while mp < c:
        mp += (mp / (vd - vp) * vp)
        if mp >= c:
            break
        drops += 1
        mp += (mp / vd + f) * vp
    return drops
print(main())
