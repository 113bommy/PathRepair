a = input()
b = input()
n = len(a)
c = []
for i in range(n):
    if a[i] == b[i]:
        c.append('0')
    else:
        c.append('1')
print(' '.join(c))