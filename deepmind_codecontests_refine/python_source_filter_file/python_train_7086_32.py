while 1:
    s = input()
    if s == '-':break
    n = input()
    for i in range(n):
        h = int(input())
        s = s[h:] + s[:h]
    print(s)