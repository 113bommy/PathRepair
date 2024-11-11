N,K=map(int,input().split())
print(sum([1,0,N*(N-1)/2,N*(N-1)*(N-2)/3,N*(N-1)*(N-2)*(N-3)*3/8][:K+1]))