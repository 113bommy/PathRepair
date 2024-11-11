N = int(input())
A = [0]*N
B = [[0]*19 for x in range(19)]
C = [0]*N
D = [0]*N
a,b,c,d,e,ans = 0,['0']*9,0,0,0,0
for i in range(N):
    c = (input()+'.0').split('.')
    b = ['0']*9
    for k,v in enumerate(c[1]):
        b[k] = v
    A[i] = int(c[0]+''.join(b))

# print(*A)

for i in range(N):
    d,e = 0,0
    while (A[i] % 2 == 0) and (d <= 18):
        A[i] //= 2
        d += 1
    while (A[i] % 5 == 0) and (e <= 18):
        A[i] //= 5
        e += 1
    C[i] = d
    D[i] = e
    B[d][e] += 1

for i in range(N):
    c = C[i]
    d = D[i]
    B[c][d] -= 1
    for j in range(18-c,19):
        for k in range(18-d,19):
            ans += B[j][k]

print(ans)