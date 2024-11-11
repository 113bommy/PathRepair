a = input().split('+')
a = sorted(a)
s = ''
for i in range(len(a)):
    s += a[i] + '+'
print(s+a[-1])
