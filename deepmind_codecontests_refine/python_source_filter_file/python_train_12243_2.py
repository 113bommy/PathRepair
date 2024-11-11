

s = input()
h, m = map(int, s.split(':'))

for i in range(120):
    hh = ('0' + str(h)) if h < 10 else str(h)
    mm = ('0' + str(m)) if m < 10 else str(m)

    if hh[::-1] == mm:
        print(i)
        break

    if m < 59:
        m += 1

    else:
        h = (h+1) % 24
        m = 0



