import sys
input = sys.stdin.readline

def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
from sys import exit
from collections import Counter
n = getN()
s = input().strip()

c = Counter(s)
# print(s, c)
if len(s) == 1:
    print(1)
    print(s)
    exit()

if c[0] != c[1]:
    print(1)
    print(c)
    exit()

else:
    print(2)
    print(s[0], s[1:])
