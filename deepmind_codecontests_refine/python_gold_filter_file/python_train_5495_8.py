K,N = map(int,input().split())
A = list(map(int,input().split()))
A+= [A[0]+K]
D = [abs(A[n+1]-A[n]) for n in range(N)]
print(K-max(D))