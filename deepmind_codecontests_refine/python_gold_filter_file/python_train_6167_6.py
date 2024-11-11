t = int(input())
for counter in range(t):
    n = int(input())
    s = input()
    a = ""
    b = ""
    k = n
    for i in range(n):
        if s[i] == '0':
            a += '0'
            b += '0'
        elif s[i] == '2':
            a += '1'
            b += '1'
        else:
            a += '1'
            b += '0'
            k = i + 1
            break
    for i in range(k, n):
        if s[i] == '0':
            a += '0'
            b += '0'
        elif s[i] == '2':
            a += '0'
            b += '2'
        else:
            a += '0'
            b += '1'
    print(a)
    print(b)
