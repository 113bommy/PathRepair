mn = [int(x) for x in input().split(' ')]
m = mn[0]
n = mn[1]
s = input().split(' ')
t = input().split(' ')

s_len = len(s)
t_len = len(t)

size = int(input())

for _ in range(size):
    year = int(input())
    out = ''
    if year % s_len == 0:
        out += s[s_len - 1]
    else:
        out += s[(year % s_len) - 1]

    if year % t_len == 0:
        out += t[s_len - 1]
    else:
        out += t[(year % t_len) - 1]
    print(out)
