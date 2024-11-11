s, x = map(int, input().split(' '))
if (s-x)%2:
    print(0)
else:
    c = bin((s-x)//2)[2:][::-1]
    t = bin(x)[2:][::-1]
    for i in range(len(t)):
        if t[i] == '1' and i < len(c) and c[i] == '1':
            print(0)
            exit(0)
    print(pow(2, bin(x)[2:].count('1'))-(2 if s==x else 0))
