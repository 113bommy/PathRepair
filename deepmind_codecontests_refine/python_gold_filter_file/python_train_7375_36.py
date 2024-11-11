N = int(input())
A = sorted(map(int, input().split()))
print(sum(A[N::2]))