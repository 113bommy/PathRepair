import sys

input = sys.stdin.readline

n, q = map(int, input().split())

s = input()
v = [0]

for i in range(n):
    v.append(v[-1] + (ord(s[i])-96))

print(v)
for _ in range(q):
    l, r = map(int, input().split())
    print(v[r]-v[l-1])
