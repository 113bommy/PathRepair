def check(li):
    b = 0
    for eb, eh in li:
        if b + eb < 0:
            return False

        b += eh

    return True


n = int(input())
s = [input() for _ in range(n)]

l = []
r = []
sm = 0
for word in s:
    h = 0
    b = 0
    for e in word:
        if e == "(":
            h += 1
        else:
            h -= 1

        b = min(b, h)

    if h > 0:
        l.append([b, h])
    else:
        r.append([b-h, -h])

    sm += h

l.sort(reverse=True)
r.sort(reverse=True)

if check(l) and check(r) and sm == 0:
    ans = "Yes"
else:
    ans = "No"
print(ans)
