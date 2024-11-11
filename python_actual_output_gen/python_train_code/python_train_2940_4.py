from sys import stdin
input = stdin.readline
s = input()
c = 0
l = []
for i in s:
    if len(l) == 0:
        l.append(i)
    if i == l[-1]:
        c += 1
        l.pop()
    else:
        l.append(i)
print('Yes' if c % 2 else 'No')
