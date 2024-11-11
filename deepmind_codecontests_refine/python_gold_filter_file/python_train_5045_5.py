n = int(input())
A = []

for i in range(n):
    a,b = map(int,input().split(' '))
    A.append((a,b))

A = sorted(A, key = lambda x : (x[0],x[1]))
cd = A[0][1]
#print(A)
for i in range(1,n):
    if A[i][1]>=cd:
        cd = A[i][1]
    else:
        cd = A[i][0]
print(cd)


