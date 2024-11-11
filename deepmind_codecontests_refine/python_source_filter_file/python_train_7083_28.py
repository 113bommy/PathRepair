s = input()
while s != "0":
    n = int(input())
    for i in range(n):
        h = int(input())
        s = s[h:] + s[:h]
    print(s)
    s = input()

