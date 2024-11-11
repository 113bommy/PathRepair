N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
if sum(A) < sum(B):
    print(-1)
    quit()
C = []
c = 0
for i in range(N):
    if A[i] < B[i]:
        c += B[i] - A[i]
    else:
        C.append(A[i] - B[i])
C.sort()
while c > 0:
    x = C.pop()
    c -= x
print(len(C))