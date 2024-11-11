n, m = map(int, input().split())
s = input()
t = input()
if '*' not in s:
    if s == t:
        print('YES')
    else:
        print('NO')
    exit(0)
ind = s.find('*')
if s[:ind] == t[:ind] and s[ind + 1:] == t[m - n + ind + 1:] and m - n + ind + 1 > ind:
    print('YES')
else:
    print('NO')