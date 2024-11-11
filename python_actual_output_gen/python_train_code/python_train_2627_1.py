num = int(input())
lst = list(map(int, input().split()))
s = sorted(set(lst))
if len(s) == 2:
    print('YES')
elif len(s) != 3:
    print('NO')
elif s[0] + s[2] == s[1] * 2:
    print('YES')
else:
    print('NO')
