import sys
input = sys.stdin.readline
N,M=map(int,input().split())
A=[[int(i)-1 for i in input().split()] for i in range(N)]
L=set()
#print(A)
def f(L):
    K=[0]*M
    for i in range(N):
        for j in range(M):
            if A[i][j] not in L:
                K[A[i][j]]+=1
                break
    a=0
    b=0
    for i in range(M):
        if a<K[i]:
            a=K[i]
            b=i
    return a,b
ans=10**9
for i in range(M):
    a,b =f(L)
    ans=min(ans,a)
    L.add(b)
    print(ans,a,b)
print(ans)