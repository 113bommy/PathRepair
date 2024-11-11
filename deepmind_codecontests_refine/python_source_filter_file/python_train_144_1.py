n, c = (input().split(" "))
A = list(map(int, input().split()))

for i in range(int(n)-1):
    if A[i+1] < A[i]:
        A[i] = A[i]-A[i+1]
    else:
        A[i] = 0

A[int(n)-1] = 0

if max(A) == 0:
    print(0)
else:
    print(max(A)-int(c))

