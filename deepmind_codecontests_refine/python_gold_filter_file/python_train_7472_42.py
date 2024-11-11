import sys
n = int(input())
x, y = [], []
for _i in range(n):
    s = input()
    p = 0
    m = 0
    for j in range(len(s)):
        if s[j]=="(":
            p += 1
        else:
            p -= 1
            m, _m = sorted([p, m])
    if p > 0:
        x.append([m, p])
    else:
        y.append([m-p, -p])

x.sort(reverse=True)
y.sort(reverse=True)
r = 0
for s, t in x:
    if r+s < 0:
        print("No")
        sys.exit()
    r += t
result = 0
for s, t in y:
    if result+s < 0:
        print("No")
        sys.exit()
    result += t
if r-result == 0:
    print("Yes")
else:
    print("No")