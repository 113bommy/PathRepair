N = int(input())
A = [list(map(int,input().split())) for l in range(N)]
B = [list(map(int,input().split())) for l in range(N)]
A.sort()
B.sort()
for i in range(N):
    a = -5
    b = -1
    for j in range(len(A)):
        if A[j][0]<B[i][0] and A[j][1]<B[i][1]:
           if a<A[j][1]:
              a = A[j][1]
              b = j
    if b!=-1:
        del A[b]
print(N-len(A))