s = [tuple(map(int, input().split())) for i in range(int(input()))]
s.sort(key=lambda q: q[0])
a = b = -1
q = 'YES'
for l, r in s:
    if a >= l:
        q = 'NO'
        break
    a = r
    if b < a: a, b = b, a
print(q)