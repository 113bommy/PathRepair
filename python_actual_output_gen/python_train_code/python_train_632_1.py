n, m = map(int, input().split(' '))
s = list(map(int, input().split(' ')))

l = {i: m for i in range(n)}
r = {i: -1 for i in range(n)}

for i, a in enumerate(s):
    l[a - 1] = min(i, l[a - 1])
    r[a - 1] = max(i, r[a - 1])
    
count = 0
for i in range(n):
    for j in range(2):
        a = i
        b = i + j - 1
        if b < 0 or b == n:
            continue
        if l[a] > r[b]:
            count += 1
print(count)