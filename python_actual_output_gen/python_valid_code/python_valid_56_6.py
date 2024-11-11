def s(x):
    return sum(map(int, list(str(x))))

n = int(input())


def solve(l, r):
    for i in range(l, r + 1):
        if i * (i + s(i)) == n:
            print(i)
            break
    else:
        print(-1)
            

l = 0
r = n

while l < r:
    m = (l + r) // 2
    if abs(l - r) < 10:
        solve(l, r)
        break
    if m * (m + s(m)) < n:
        l = m - 1
    else:
        r = m + 1
else:
    if l * (l + s(l)) == n:
        print(l)
    else:
        print(-1)
