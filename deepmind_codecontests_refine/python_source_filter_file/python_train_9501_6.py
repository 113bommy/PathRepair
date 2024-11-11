def f(a):
    if len(a) == 0:
        return 0
    r, l = 0, 0
    for i in a:
        if i == 'L':
            l += 1
        else:
            r += 1
    return max(0, (l + 1) // 3) + max(0, (r + 1) // 3)

for _ in range(int(input())):
    n = int(input())
    s = input()
    t = 0
    if n == 2:
        print(0)
        continue
    for i in s:
        t += (i == 'L')
    if t % n == 0:
        print(n // 2)
        continue
    a = []
    for i in s:
        a.append(i)
    s = -1
    for i in range(n + 1):
        if a[i % n] == 'R' and a[(i + 1) % n] == 'L':
            a[i % n] = "Q"
            a[(i + 1) % n] = "Q"
            s = (i + 2) % n
    new = [[]]
    now = 0
    while a[s] != "W":
        if a[s] == "L" or a[s] == "R":
            new[now].append(a[s])
        else:
            now += 1
            new.append([])
        a[s] = "W"
        s += 1
        s %= n
    ans = 0
    for i in new:
        ans += f(i)
    print(ans)