N,A,B= map(int, input().split())
X = min(A, B)
Y = max(0, A+B-N)
print(X, Y)