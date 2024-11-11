N = int(input())
A = list(map(int, input().split()))

Y = [sum(A) - 2 * sum(A[1::2])]
for i in range(1, N):
    Y.append(2 * A[i-1] - Y[i-1])

print(Y)
