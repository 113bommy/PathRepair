N = int(input())
A = sorted(list(map(int, input().split())))
print(sum(A[N:N*2]))
