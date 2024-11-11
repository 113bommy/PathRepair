N=int(input())
P=list(map(int,input().split()))

D=sorted(D)
K=D[N//2]-D[N//2-1]
print(K)