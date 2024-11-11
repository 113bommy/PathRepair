def to_w(w1, m1):
    t = 100
    while w ** t > m:
        t -= 1
    at = [0] * (t + 1)
    for i in range(t, -1, -1):
        at[i] = m1 // (w1 ** i)
        m1 = m1 % (w1 ** i)
    return at
w, m = list(map(int, input().split()))
n = to_w(w, m)
for i in range(len(n)):
    if n[i] != 0 and n[i] != 1 and n[i] != w and n[i] != w - 1:
        print(n, i)
        print("NO")
        exit()
    if n[i] == w - 1:
        if i != len(n) - 1:
            n[i + 1] = (n[i + 1] + 1)
            n[i] = 0
        else:
            n.append(1)
    if n[i] == w:
        if i != len(n) - 1:
            n[i] = 0
            n[i + 1] += 1
        else:
            n.append(1)
print("YES")
