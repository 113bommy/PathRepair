n = int(input())
a = []
for i in range(n):
    m, h = input().split(':')
    m = int(m)
    h = int(h)
    a.append(m * 60 + h)
a.sort()

ans = 0
for i in range(n):
    ans = max(ans, a[i] - a[i - 1] - 1)
ans = max(ans, 1440 + a[0] - a[-1])
if n == 1:
    print('23:59')
else:
    hh = ans // 60
    mm = ans % 60
    hh = str(hh)
    mm = str(mm)
    if len(hh) == 1:
        hh = '0' + hh
    if len(mm) == 1:
        mm = '0' + mm
    print(hh + ':' + mm)
