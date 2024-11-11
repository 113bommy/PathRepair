N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
l = sum(B)-sum(A)
c = 0
for k in range(N):
    if A[k]>B[k]:
        c += A[k]-B[k]
    elif A[k]<B[k]:
        c += (B[k]-A[k])//2

print("Yes" if l>=c else "No")
