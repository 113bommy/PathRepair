s = input().split()
n = int(s[0])
x = int(s[1])
cnt = 0
for _ in range(n):
    s = input().split()
    if s[0] == '+':
        x += int(s[1])
    else:
        d = int(s[1])
        if x > d:
            x -= d
        else:
            cnt += 1
print('{} {}'.format(x, cnt))
