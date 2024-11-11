s = input()
while s != "-":
    m = int(input())
    for i in range(m):
        h = int(input())
        s = s[h:] + s[:h]
    print(s)
    s = input()

