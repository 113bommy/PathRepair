N,M=map(int,input().split())
X=sorted(list(map(int,input().split())))
print(sum(sorted([X[i+1]-X[i] for i in range(M-1)])[:-N+1]))