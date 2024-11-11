n, k = map(int, input().split())
v = []
for i in range(n):
    abc = [x for x in input().split()]
    a = int(abc[0])
    b = int(abc[1])
    c = abc[2]
    if c == 'W':
        b += k
    v.append((a % (2*k), b % (2*k)))

s = [[0 for _ in range(3*k+1)] for _ in range(3*k+1)]
s2 = [[0 for _ in range(k+1)] for _ in range(k+1)]
s3 = [[0 for _ in range(k+1)] for _ in range(k+1)]

for i in range(n):
    s[v[i][1]][v[i][0]] += 1
    s[v[i][1]+k][v[i][0]+k] += 1
    s[v[i][1]+k][v[i][0]] -= 1
    s[v[i][1]][v[i][0]+k] -= 1

for i in range(3*k):
    for j in range(3*k):
        s[i+1][j] += s[i][j]
for i in range(3*k):
    for j in range(3*k):
        s[i][j+1] += s[i][j]

for i in range(3*k):
    for j in range(3*k):
        c = (i//k+j//k) % 2
        if c == 0:
            s2[i % k][j % k] += s[i][j]
        else:
            s3[i % k][j % k] += s[i][j]
res = 0

for i in range(k):
    for j in range(k):
        #res = max(res, s2[i][j])
        res = max(res, s3[i][j])

print(res)
