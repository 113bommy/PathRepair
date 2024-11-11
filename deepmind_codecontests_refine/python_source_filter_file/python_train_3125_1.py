N = int(input())
A = list(map(int, input().split()))
count = 0
flag = True
while flag:
    flag = False
    for i in range(N-1, 1):
        if(A[i] < A[i-1]):
            A[i], A[i-1] = A[i-1], A[i]
            flag = True
            count += 1
print(*A)
print(count)
            