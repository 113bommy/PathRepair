n, t = map(int, input().split())
s = list(map(int, input().split()))
pos = 0
while pos < t:
    pos = s[pos] + pos + 1
if pos != t:
    print('NO')
else:
    print('YES')
