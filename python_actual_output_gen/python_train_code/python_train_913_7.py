n, m = input().split()
n = int(n)
m = int(m)
d = m/n
v = 0
while d != 1 :
    if d%6 == 0:
        d = d/6
        v += 2
    elif d%2 == 0:
        d = d/2
        v += 1
    elif d%3 == 0:
        d = d/3
        v += 1
    else:
        break


if d == 1 and v ==0 :
    print(1)
elif d == 1 and v > 0:
    print(v)
else:
    print(-1)








