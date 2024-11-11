
H,W = map(int,input().split())

a = []

N = 0
ans = []

for i in range(H):

    A = list(map(int,input().split()))

    a.append(A)

for i in range(H-1):

    for j in range(W):

        if a[i][j] % 2 == 1:

            a[i+1][j] += 1

            ans.append([i+1,j+1,i+2,j+1])

            N += 1

for j in range(W-1):

    if a[-1][j] % 2 == 1:

        a[-1][j+1] += 1

        ans.append([N+1,j+1,N+1,j+2])

        N += 1

print (N)

for i in ans:

    print (" ".join(map(str,i)))