N = int(input())
A = list(map(int, input().split()))
count = 0
Flag = True
while Flag:
    Flag = False
    for i in range(N-1, 1):
        if(A[i] < A[i-1]):
            A[i], A[i-1] = A[i-1], A[i]
            Flag = True
            count += 1
print(*A)
print(count)
            