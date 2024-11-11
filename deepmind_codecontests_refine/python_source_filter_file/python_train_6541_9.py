N,C = map(int,input().split())
A = [[0 for _ in range(C)] for j in range(200001)]
for i in range(N):
    s,t,c = map(int,input().split())
    for j in range(s*2-1,t*2):
        A[j][c-1] = 1
R = 0
for i in range(200001):
    sumA = sum(A[i])
    if R < sumA:
        R = sumA
print(R)
