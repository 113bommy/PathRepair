n = int(input())
A = sorted(list(map(int, input().split())))
print(sum(A[n::2]))