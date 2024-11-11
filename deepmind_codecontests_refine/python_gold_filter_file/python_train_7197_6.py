n = int(input())


def intersect(a, b, c, d):
    if c < a:
        a, b, c, d = c, d, a, b
    b -= a
    c -= a
    d -= a
    a -= a
    if d <= b:
        return d - c + 1
    return b - c + 1


a, b = 0, 0
ans = 1
for _ in range(n):
    na, nb = map(int, input().split())
    peresech = intersect(a, na, b, nb)
    ans += max(0, peresech - (a==b))
    a, b = (na, nb)
print(ans)