T = int(input())
for _ in range(T):
    n = int(input())
    s = input()

    try:
        i = s.index('ab')
    except:
        try:
            i = s.index('ba')
        except:
            i = -1

    if i != -1:
        l, r = i + 1, i + 3
        print("{} {}".format(i + 1, i + 2))
    else:
        print("-1 -1")
        