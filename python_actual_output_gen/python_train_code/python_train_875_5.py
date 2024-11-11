n,m=map(int,input().split())
A=[0]*n
print(A)
for i in range(m):
    a,b=map(int,input().split())
    A[a-1] += 1
    A[b-1] += 1
for h in range(n):
    print(A[h])