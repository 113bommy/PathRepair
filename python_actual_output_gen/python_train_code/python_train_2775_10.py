a,b = map(int, input().split())
s = 1
nt = 0
while 1:
    if nt == 0:
        if a < s:
            print('Vladic')
            break
        a -= s
    elif nt == 1:
        if b < s:
            print('Valera')
            break
        b -= s
    s += 1
    nt = (nt + 1)%2