N,L=map(int,input().split())
a=[abs(L+i-1) for i in range(1,N+1)]
print(a)
print(N*L-L+sum([i for i in range(1,N+1)])-N-a.index(min(a)))