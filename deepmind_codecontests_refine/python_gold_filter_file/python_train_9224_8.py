n = int(input())
a = []
for i in range (n):
    x = input()
    if x not in a:
        a.append(x)
        print('NO')
    else:
        print('YES')
