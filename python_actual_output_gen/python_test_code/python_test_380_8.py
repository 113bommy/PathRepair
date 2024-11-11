n = int(input())
A = [int(i) for i in input().split()]
A = list(set(A))
A.sort()
if len(A)>1:
    print(A[1])
else:
    print(A[0])