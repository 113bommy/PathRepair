n, h, a, b, k = [int(j) for j in input().split()]
for i in range(k):
    t1, f1, t2, f2 = [int(j) for j in input().split()]
    if t1 == t2:
        print(abs(f1 - f2))
    else:
        p = abs(a - f1)
        q = abs(b - f1)
        c = abs(t2 - t1)
        d = abs(f2 - a)
        e = abs(f2 - b)
        # if p < q:
        #     print(p + abs(t2 - t1) + abs(f2 - a))
        # elif p == q:
        #     if f2 > f1:
        #         print(q + abs(t2 - t1) + abs(f2 - b))
        #     else:
        #         print(q + abs(t2 - t1) + abs(f2 - a))
        # else:
        #     print(q + abs(t2 - t1) + abs(f2 - b))
        if f1 >= b and f2 >= b:
            print(q + abs(t2 - t1) + abs(f2 - b))
        elif f1 <= a and f2 <= a:
            print(p + abs(t2 - t1) + abs(f2 - a))
        elif f1 >= b and f2 <= a:
            print(q + c + p)
        elif f1 >= b and f2 <= b and f2 >= a:
            print(q + c + e)
        elif f1 <= a and f2 <= b and f2 >= a:
            print(p + c + d)
        elif f1 <= a and f2 >= b:
            print(p + c + d)
        elif f1 >= a and f1 <= b and f2 >= b:
            print(q + c + e)
        elif f1 <= b and f1 >= a and f2 <= a:
            print(p + c + d)
        elif f1 >= a and f1 <= b and f2 >= a and f2 <= b:
            print(c + abs(a - b))
