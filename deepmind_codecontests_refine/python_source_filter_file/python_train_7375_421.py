N = int(input())
A = sorted([int(i) for i in input().split()])
A.reverse()
print(sum(A[1:2*N+2:2]))