q = int(input())
w = list(map(int, input().split()))
e = list(map(int, input().split()))
z = 0
r = max(e)
for i in range(q):
    if e[i] == r:
        z = i
del(e[i])
k = max(e)
if k + r < sum(w):
    print('NO')
else:
    print('YES')
