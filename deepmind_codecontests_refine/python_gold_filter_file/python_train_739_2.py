N = int(input())
L = []
for _ in range (N):
    L.append(int(input()))
for i in range (1 << N):
    k = 0
    for j in range (N):
        if i & (1<<j):
            k += L[j]
        else:
            k -= L[j]
    if k%360 == 0:
        print('YES')
        exit()
print('NO')