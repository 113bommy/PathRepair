import sys
n, x = input().split()
n = int(n)
x = int(x)
l = []
c = 0
for line in sys.stdin:
    print(line[0]+line[2:-1])
    l.append(int(line[0]+line[2:-1]))
    c += 1
    if c >= n:
        break
summ = x
bad = 0
for h in l:
    if h < 0:
        if summ < -h:
            bad += 1
        else:
            summ += h
    else:
        summ += h
print(summ, bad)
