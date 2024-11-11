N = int(input())
A = list(map(int,input().split()))
A.sort()
K = N-1
ans = []
while(K>1):
    if A[K-1] < 0:
        break
    l = A[0] - A[K]
    ans.append(str(A[0])+" "+str(A[K]))
    A[0] = l
    K -= 1
if K == 1:
    ans.append(str(A[1])+" "+str(A[0]))
    print(A[1]-A[0])
else:
    b = A[K]
    for i in range(K-1,0,-1):
        c = A[i]
        ans.append(str(b)+" "+str(c))
        b = b-c
    ans.append(str(b)+" "+str(A[0]))
    print(b-A[0])
for p in ans:
    print(p)