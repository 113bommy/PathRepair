# IAWT
n, k, q = list(map(int, input().split()))
l = [list(map(int, input().split())) for i in range(n)]
qs = [list(map(int, input().split())) for i in range(q)]

def answer(q):
    a, b = q
    if a == 1:
        print(l3[b-1])
    else:
        print(l3[b-1]-l2[a-2])

l2 = [0] * 200000
l3 = [0] * 200000
adds = [0] * 200000
mins = [0] * 200000
for r in l:
    adds[r[0]-1] += 1
    mins[r[1]-1] += 1
l2[0] = adds[0] - mins[0]
if adds[0] >= k: l3[0] = 1
for i in range(1, 200000):
    l2[i] = l2[i-1] + adds[i]
    if l2[i] >= k: l3[i] = 1
    l2[i] -= mins[i]

for i in range(1, 200000):
    l3[i] = l3[i-1] + l3[i]

for q in qs:
    answer(q)
