while True:
    s = input()
    if s == '-': break
    n = int(input())
    for i in range(n):
        x = int(input())
        s = s[x:] + s[:x]
    print(s)

