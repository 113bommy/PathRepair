N = int(input())
A = []
for i in range(1, N+1):
    l, r = map(int, input().split())
    A.append([l, r, i])

A.sort(key=lambda x:x[0])

if N == 1:
    print(-1, -1)
    quit()

a = A[0][1]
for i in range(1, N):
    if A[i][0] == A[i-1][0] and A[i][1] > A[0][1]:
        print(A[i-1][2], A[i][2])
        quit()
    elif A[i][1] <= a:
        print(A[i][2], A[i-1][2])
        quit()
    else:
        if i == N-1:
            print(-1, -1)
            quit()
        else:
            a = A[i][1]