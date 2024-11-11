n, h, a, b, k = list(map(int, input().split()))

def ans(t1, f1, t2, f2):
    res = abs(t2 - t1)
    if res == 0:
        res += abs(f2 - f1)
    else:
        ff = -1
        if f1 > b:
            res += f1 - b
            ff = b
        elif f1 < a:
            res += a - f1
            ff = a
        else:
            ff = f1
        res += abs(ff - f2)

    return res

for i in range(k):
    t1, f1, t2, f2 = list(map(int, input().split()))
    print(ans(t1, f1, t2, f2))

