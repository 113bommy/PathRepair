N = int(input())
A = list(map(int, input().split()))
sorted_A = sorted(A)
print(sum(sorted_A[N:3*N:2]))