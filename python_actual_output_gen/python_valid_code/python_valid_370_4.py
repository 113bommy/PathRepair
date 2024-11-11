n, d = map(int, input().split())
m = 0
c = 0
for i in range(d):
    checker = False
    s = input()
    for j in s:
        if '0' == j:
            checker = True
            break
    if checker:
        c += 1
    else:
        if m < c:
            m = c
            c = 0
print(max(m, c))