n = int(input())
s = list(input())

e = s.count('E')
w = 0
c = 10**5
for i in range(n):
    if s[i] == 'E':
        e -= 1
        c = min(c, w + e)
    else:
        c = min(c, w + e)
        w += 1

print(c)
