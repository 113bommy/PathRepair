N, A, B = map(int, input().split())
X = min(A, B)
Y = max(A+B-N, 0)
print(X, Y)