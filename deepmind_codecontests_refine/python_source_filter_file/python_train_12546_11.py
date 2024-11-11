n = int(input())
a = [int(i) for i in input().split()]
s = sum(a)
e = -1
m = 1000000
for e in a:
    if e % 2 == 1: m = min(e, m)
if s % 2 == 0: print(s)
else: print(s - m)