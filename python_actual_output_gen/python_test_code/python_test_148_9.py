N,M=map(int,input().split())


A=[int(i) for i in (input().split(" "))]

A.sort()

BC = [list(map(int,input().split())) for _ in range(M)]

BC.sort(key=lambda x:x[1],reverse=True)

for b,c in BC:
    A.expend([c]*b)
    if len(A)>2*N:
        break

A.sort(reverse=True)
suma=0
#for i in A:
#    suma+=i

print(sum(A[:N]))