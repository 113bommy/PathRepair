n = int(input())
s = [input() for i in range(n)]
l, r = [], []
for i in s:
    a, b = 0, 0
    for j in range(len(i)):
        if i[j] == "(":
            b += 1
        if i[j] == ")":
            if b <= 0:
                a += 1
            else:
                b -= 1
    if b - a > 0:
        l.append([a, b])
    else:
        r.append([a, b])
l.sort(key=lambda x:x[0])
r.sort(key=lambda x:x[1], reverse=True)
li = l + r
ans = 0
for i in li:
    ans -= i[0]
    if ans < 0:
        exit(print("No"))
    ans += i[1]
print("Yes" if ans == 0 else "No")