N,L=map(int,input().split())
a=list(range(N,N+L))
print(sum(a)-min(a,key=abs))