import math
ts = int(input())

for case in range(ts):
    a, b = map(int, input().split())
    gc = math.gcd(a, b)
    koto = (b - 1) // gc
    baki = b // gc

    gc_lis = []

    for i in range(2, int(math.sqrt(baki)) + 1):
        if baki % i == 0:
            gc_lis.append(i)
            while baki % i == 0:
                baki //= i

    if baki > 1:
        gc_lis.append(baki)

    total = koto
    for j in range(1, (1<<len(gc_lis))):
        mul = 1
        cnt = 0
        for k in range(0, len(gc_lis)):
            if (j & (1<<k)) != 0:
                mul *= gc_lis[k]
                cnt += 1

        if cnt % 2 == 1:
            total -= (koto // mul)
        else:
            total += (koto // mul)

    print(total)