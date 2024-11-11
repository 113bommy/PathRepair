from sys import stdin
input = stdin.readline
n, m = map(int, input().split())
have = set(list(map(int, input().split())))
cur = 0
p = []
for i in range(1, 110002):
    if cur + i > m:
        break
    if i in have:
        continue
    if cur + i <= m:
        cur += i
        p.append(str(i))
print(len(p))
print(" ".join(p))
