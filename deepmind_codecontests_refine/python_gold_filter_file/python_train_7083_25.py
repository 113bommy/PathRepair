while True:
    s = input()
    if s == '-':
        break

    m = int(input())
    for mi in range(m):
        h = int(input())
        s = s[h:] + s[0:h]
    print(s)