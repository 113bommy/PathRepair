n = int(input())
for i in range(n):
    s = list(input())
    z = True
    for j in range(len(s) // 2):
        if s[j] != s[-j - 1]:
            z = False
            break
    output = list()
    if not z:
        output = s
    else:
        for j in range(len(s) // 2):
            if s[j] != s[len(s) // 2]:
                a = s[j]
                s[j] = s[len(s) // 2]
                s[len(s) // 2 + 1] = a
                output = s
                break
    if len(output) == 0:
        print(-1)
    else:
        for k in range(len(s)):
            print(output[k], end='')
        print()