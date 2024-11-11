def r(t=int):
    return list(map(t, input().split()))


def ri(t=int):
    return t(input())


def cd(it):
    ret_val = dict()
    for v in it:
        ret_val[v] = ret_val.get(v, 0) + 1
    return ret_val


n, h, s, e = r()
aa = r()


stack = [[0] * (n + 2) for _ in range(n + 1)]
ss = 0
for i, ai in enumerate(aa):
    ss += ai
    for ii in range(i + 2):
        b = stack[i - 1][ii]
        a = stack[i - 1][ii - 1]
        m = max(a, b)
        if s <= (ss - ii + h) % h <= e:
            stack[i][ii] = m + 1
        else:
            stack[i][ii] = m
print(max(stack[i]))
