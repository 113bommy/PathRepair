q = int(input())
for k in range(q):
    n = int(input())
    s = input()
    if s[0] < s[1] or len(s) > 2:
        print('YES')
        print('2')
        print(s[0], end = ' ')
        for j in range(1, n):
            print(s[j], end = '')
            print()
    else:
        print()
        print('NO')

