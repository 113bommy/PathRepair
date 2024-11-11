"""
Brandt Smith, Lemuel Gorion and Peter Haddad

codeforces.com

Problem 115B
"""
import sys

k = int(input())

if k > 36:
    print(-1)
    sys.exit()

if k == 0:
    print(1)
    sys.exit()

if k == 1:
    print(6)
    sys.exit()

for i in range(0, k // 2):
    print(8, end = '')

if k % 2:
    print(0)


