A, B, K=map(int, input().split())

A, B=A-min(A, K), B+min(0, A-K)

print(A, B)