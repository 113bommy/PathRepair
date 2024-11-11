while True:
    s = input()
    if s == '-':
        break
    n = int(input())
    for _ in range(n):
        h = int(input())
        s = s[h:] + s[:h]
    print(s)
