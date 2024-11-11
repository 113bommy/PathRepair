from sys import stdin, stdout
from collections import deque

h1, a1, c = map(int, stdin.readline().split())
h2, a2 = map(int, stdin.readline().split())
ans = deque()

strike = h2 // a1 + int((h2 % a1) != 0)
for i in range(strike):
    ans.append('STRIKE')

l, r = strike - 1, 500

while r - l > 1:
    m = (l + r) >> 1
    
    health = (m - strike) * c + h1
    
    if health > (m - 1) * a2:
        r = m
    else:
        l = m

for i in range(r - strike):
    ans.appendleft('HEAL')

stdout.write(str(len(ans)) + '\n')
for v in ans:
    stdout.write(v + '\n')