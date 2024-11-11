t = int(input())
for i in range(t):
    for k in range(9):
        s = list(input())
        for j in range(9):
            if int(s[j]) == 1:
                s[j] = '2'
                print(*s)