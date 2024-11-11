import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")

input()
p = []
n = []
z = 0
for i, j in zip(map(int, input().split()), map(int, input().split())):
    if i - j > 0:
        p.append(i - j)
    elif not i - j:
        z += 1
    else:
        n.append(i - j)
n.sort(reverse=True)
p.sort()
ans = len(n) * (len(n) - 1) / 2 + len(n) * z
count = 0
j = 0
for i in p:
    while j < len(n) and i + n[j] > 0:
        count += 1
        j += 1
    ans += count
print(int(ans))
