from sys import stdin, stdout
from math import pow
from os import path
if path.exists('inp.txt'):
    stdin = open("inp.txt", "r")

d = [0 for i in range(26)]
q = []
n = int(stdin.readline())
s = stdin.readline()
cur = 'a'

def check(x):
    for i in range(x + 1, 26):
        if d[i] == 1:
            return 0
    return 1

for i in range(n):
    if s[i] < cur:
        q.append(1)
        if not check(ord(s[i]) - ord('a')):
            print("NO")
            exit()
        d[ord(s[i]) - ord('a')] = 1
    else:
        cur = s[i]
        q.append(0)
print("YES")
for v in q:
    print(v, end=' ')
