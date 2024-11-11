from operator import itemgetter
import functools as ft

if __name__ == '__main__':
    n = int(input())
    s = lambda v, a, b: "%s ml. from cup #%s to cup #%s." % (v, a, b)
    a, d, ans = list(), dict(), ["Exemplary pages.", "Unrecoverable configuration."]

    for i in range(n):
        k = int(input())
        a.append(k)
        d[k] = d.get(k, 0) + 1
    d = sorted(d.items(), key=itemgetter(1))
    k = [x[0] for x in d if x[1] == 1]
    r = [x[0] for x in d if x[1] > 1]
    if len(d) == 1:
        print(ans[0])
    elif (len(d) == 2 or len(d) == 3) and len(k) > 1:
        t = ft.reduce(lambda x, y: x + y, k)
        mx, mn = max(k), min(k)
        if len(k) == 2 and (len(k) == len(d) and t % 2 == 0) or (len(k) == len(d) - 1 and abs(mx - r[0]) + mn == r[0]):
            print(s(abs(mx - mn) // 2 if len(k) == len(d) else abs(mx - r[0]), a.index(mn) + 1, a.index(mx) + 1))
        elif len(k) == 3 and len(k) == len(d) and t // 3 == t - (mx + mn) and t - (mx + mn) == 2 * (mx + mn) - t:
            print(s(t - (mx + mn), a.index(mn) + 1, a.index(mx) + 1))
        else:
            print(ans[1])
    else:
        print(ans[1])