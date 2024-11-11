k, l, r, t, x, y = list(map(int, input().split()))
import sys

if y < x:
    if k + y <= r:
        k += y
    k -= x

    nb_days = int((k - l) / (x - y)) + 1
    print("Yes" if nb_days >= t else "No")

elif x < y:
    memo = {}
    nb_days = 0

    if (k - l) % x == k - l:
        k += y
        if k > r:
            print("No")
            sys.exit()
    t2 = t
    while True:
        nb_days += (k - l) // x
        k = (k - l) % x + l
        if k in memo:
            print("Yes")
            break
        memo[k] = True
        if k + y > r:
            if nb_days < t:
                print("No")
                break
            else:
                print("Yes")
                break
        else:
            k += y
else:
    if k + y <= r:
        print("Yes")
    elif k - y >= l:
        print("Yes")
    else:
        print("No")