'''
    Author : thekushalghosh
    Team   : CodeDiggers
'''
import sys,math
input = sys.stdin.readline
n = int(input())
q = [1,2]
for i in range(100):
    if q[-1] % 2 == 0:
        q = q + [q[-1] + q[-2],q[-1] + q[-2] + 1]
    else:
        q = q + [(2 * q[-1]) + 1,(2 * q[-1]) + 2]
if n in q:
    print(1)
else:
    print(0)