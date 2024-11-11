n = int(input())
s = input()

e = s.count('E')
w = 0
a = e+w
for i in range(1,n):
    if s[i] == 'E':
        e -= 1
    if s[i-1] == 'W':
        w += 1
    a = min(a, e+w)
print(a)