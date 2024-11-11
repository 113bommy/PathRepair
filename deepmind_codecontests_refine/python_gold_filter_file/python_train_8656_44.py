t = int(input())
for case in range(t):
    n = int(input())
    s = input()
    if n >= 11 and '8' in s[:-10]:
        print('YES')
    else:
        print('NO')
