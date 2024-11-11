N, X=map(int, input().split())
A=[int(input(for _ in range(N)))]
rest=X-sum(A)
print(rest//min(A)+N)