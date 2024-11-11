n, a = map(int, input().split())
A = input()
dd = 5
for i in range(n-a):
    if A[i] == A[i + a]:
        if A[i] == '.':
            A = A[:i] + '1' + A[i + 1:]
            A = A[:i+a] + '0' + A[i + a + 1:]
            dd = 5
            break
        else:
            dd = 2
    else:
        if A[i] == '.':
            if A[i+a] == '0':
                A = A[:i] + '1' + A[i + 1:]
            elif A[i+a] == '1':
                A = A[:i] + '0' + A[i + 1:]
        if A[i+a] == '.':
            if A[i] == '0':
                A = A[:i+a] + '1' + A[i + a + 1:]
            elif A[i] == '1':
                A = A[:i+a] + '0' + A[i+a + 1:]
        dd = 5
        break
if dd == 2:
    print('No')
else:
    for i in range(n):
        if A[i] == '.':
            print(1, end='')
        else:
            print(A[i], end = '')