n, m = input().split()
chests = list(map(int, input().split()))
keys = list(map(int, input().split()))

a = len(chests)
b = len(keys)
ca = 0
cb = 0
for i in range(a):
    if chests[i] % 2 == 1:
        ca += 1

for j in range(b):
    if keys[j] % 2 == 1:
        cb += 1

ra = min(ca, b - cb)
rb = min(cb, a - ca)

print(ra + rb)