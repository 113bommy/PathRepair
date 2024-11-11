def point_sum(st):
    s = 0
    for i in range(14):
        if st[i] % 2 == 0:
            s += st[i]
    return s

def step(st, i):
    a = st.copy()
    element = a[i]
    a[i] = 0
    q, w = divmod(element, 14)
    for z in range(14):
        point = (z + i + 1) % 14
        a[point] += q
        if z <= w:
            a[point] += 1
    return point_sum(a)

st = list(map(int, input().split()))
results = []
for i in range(14):
    if st[i] == 0:
        results.append(point_sum(st))
    else:
        results.append(step(st, i))
print(max(results))
