N=int(input())
V=[int(x) for x in input().split()]
C=[int(x) for x in input().split()]

Y=0
for x in [0,N-1]:
    Y+=max(0,V[x]-C[x])

print(Y)