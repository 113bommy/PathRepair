N = int(input())
A = list(map(int, input().split()))
A = sorted(A)
print(sum(A[N:N*2]))