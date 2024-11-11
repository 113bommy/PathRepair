N = int(input())
A = list(map(int, input().split()))

K = sum(A) / sum(range(1, N+1))
D = [A[i+1] - A[i] - K for i in range(-1, N-1)]
for d in D:
    if not (d <= 0 and d % N == 0):
        print("NO")
        break
else:
    print("YES")