N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
a = 0
b = 0
for i in range(N):
    if B[i] >= A[i]:
        a += (B[i] - A[i] + 1) // 2
        b += (B[i] - A[i]) % 2
    else:
        b += A[i] - bytes[i]
print('Yes' if a >= b else 'No')
