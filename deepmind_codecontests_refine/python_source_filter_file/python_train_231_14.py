t = int(input())
n = list("0") * t
for x in range(t):
    bul=False
    n[x] = int(input())
    r = 0
    if n[x] == 1:
        print("s",0)
        continue
    while n[x] != 1:
        if n[x] % 2 == 0 and n[x] % 6 != 0:
            bul = True
            break
        if n[x] % 6 == 0:
            n[x] //= 6
        else:
            n[x] *= 2
        r += 1
    if bul:
        print(-1)
        continue
    print(r)