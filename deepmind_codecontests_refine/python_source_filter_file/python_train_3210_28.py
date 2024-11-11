A, B, K = map(int, input().split())
for i in range(A,B+1):
    if (i <= A + K - 1) or (i >= B - K + 1):
        print(i)