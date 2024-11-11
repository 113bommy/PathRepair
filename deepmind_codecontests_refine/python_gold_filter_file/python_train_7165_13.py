N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
a = 0
b = 0
for i in range(N):
    if A[i] > B[i]:
        a += A[i] - B[i]
    else:
        b += (B[i] - A[i])//2

print("Yes") if a <= b else print("No")