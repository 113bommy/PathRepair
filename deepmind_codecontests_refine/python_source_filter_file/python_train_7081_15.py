while True:
    s = input()
    if s == '-':
        break

    n = int(input())
    for mi in range(m):
        h = int(input())

        s = s[h:] + s[:h]

    print(s)