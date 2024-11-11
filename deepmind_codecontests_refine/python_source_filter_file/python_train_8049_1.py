def get_div(w):
    res = []
    for d in range(1, w):
        if not w % d:
            res.append(d)
    if w % 2:
        return res
    else:
        return res[:-1]


n = int(input())
a = list(map(int, input().split()))
m = None
for step in get_div(n):
    for i in range(n // step):
        if m:
            s = sum(a[i::step])
            if s > m:
                m = s
        else:
            m = sum(a[i::step])
print(m)
