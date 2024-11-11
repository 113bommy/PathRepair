n, t = map(int, input().split())
s = list(map(int, input().split()))
pos = 1
while pos < t:
    pos = s[pos-1] + pos
if pos != t:
    print('NO')
else:
    print('YES')
