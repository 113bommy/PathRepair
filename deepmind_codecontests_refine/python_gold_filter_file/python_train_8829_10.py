N = int(input())
A = list(map(int, input().split()))
B = [A[i]-i-1 for i in range(N)]

B.sort()
b = B[N//2]
print(sum([abs(A[i]-i-b-1) for i in range(N)]))