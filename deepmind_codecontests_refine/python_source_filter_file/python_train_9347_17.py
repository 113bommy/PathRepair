N = int(input())
A = [0]
Sum = 0
for s in input().split():
    s = int(s)
    Sum += s
    A.append(Sum)
mid = A[-1]//2
ans = 2*min(abs(A[i]-mid) for i in range(N+1))
print(int(ans))