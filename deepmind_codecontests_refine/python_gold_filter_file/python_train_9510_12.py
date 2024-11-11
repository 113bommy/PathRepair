n = int(input())
A = list(map(int,input().split()))
for i, q in enumerate(A):
    A[i] = [q, i]
if n == 1:
    print(1)
else:
    A.sort()
    if A[0][0] == A[1][0]:
        print("Still Rozdil")
    else:
        print(A[0][1] + 1)