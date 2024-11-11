import sys

nx = sys.stdin.readline()
n, x = (int(i) for i in nx.strip().split(' '))

s = sys.stdin.readline()
s = set(int(i) for i in s.strip().split(' '))


a = 0
for i in range(0, 3):
    if i not in s:
        a += 1

if x in s:
    a += 1
print(a)


