n = int(input())
A = list(map(int, input().split()))
A.sort()
B = []
for i in range((n - 1) // 2 + 1):
    if A[i] == n - i - 1:
        B.append(A[i])
    else:
        B.append(A[i])
        B.append(A[n - i - 1])

b = True
for i in range(1, n):
    if (i + 1) % 2 == 0:
        if B[i] >= B[i - 1]:
            pass
        else:
            b = False
            break
    else:
        if B[i] <= B[i - 1]:
            pass
        else:
            b = False
            break
if b:
    print(*B)
else:
    print('Impossible')