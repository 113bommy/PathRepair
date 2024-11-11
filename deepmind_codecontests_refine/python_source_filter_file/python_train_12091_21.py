n, m, k = map(int, input().split())
f = list(reversed(sorted(list(map(int, input().split())))))
x = 0
if m % (k + 1) == 0:
    x = m/(k + 1)
    print(str(int((x*((k*f[0]) + (f[1]))))))
else:
    x = m/(k + 1)
    answ = int((x*((k*f[0]) + (f[1]))))
    answ += f[0]* (m % (k + 1))
    print(answ)

