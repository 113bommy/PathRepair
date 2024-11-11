N = int(input())
A = list(map(int, input().split()))

print(sum(sorted(A)[N:2*N]))