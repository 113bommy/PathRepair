n, p = map(int, input().split())
def count(s):
    c = 0
    b = list(bin(s))
    b.pop(0)
    b.pop(0)
    for i in b:
        if i == '1':
            c += 1
    return c
i = 1
if p > 0:
    l = n/p+1
    while i <= l:
        if count(n - i*p) <= i:
            print(i)
            break
        else:
            i += 1
    else:
        print('-1')
else:
    i = 1
    while True:
        if count(n - i*p) <= i:
            print(i)
            break
        else:
            i += 1