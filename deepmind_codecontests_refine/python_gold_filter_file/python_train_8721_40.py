N,M=map(int,input().split())
A=sorted(map(int,input().split()))
print(['No','Yes'][A[-M]>=sum(A)/(4*M)])