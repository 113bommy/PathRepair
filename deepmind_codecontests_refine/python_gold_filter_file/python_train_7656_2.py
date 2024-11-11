num = int(input())
lst = list(map(int, input().split()))
s = sorted(set(lst))
if len(s) > 3 or (len(s) == 3 and s[0] + s[2] != s[1] * 2):
    print('NO')
else:
    print('YES')
