s = input()
k = int(input())

ss = s + s

if len(set(s)==1):
    print(int((len(s)*k)/2))
else:
    a=0
    prev = "?"
    for v in s:
        if v==prev:
            a += 1
            prev = "?"
        else:
            prev = v

    b=0
    prev = "?"
    for v in ss:
        if v==prev:
            b += 1
            prev = "?"
        else:
            prev = v

    print(a+(b-a)*(k-1))