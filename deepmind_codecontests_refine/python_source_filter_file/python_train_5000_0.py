r,c = map(int,input().split())

A = [list(map(int,input().split())) for i in range(c)]
for i in range(c):
    for j in range(r):
        print(A[i][j],end=" ")
    print(sum(A[i]))
for i in range(c):
    ans = 0
    for j in range(r):
        ans += A[j][i]
    print(ans,end=" ")
print(sum(map(sum,A)))

