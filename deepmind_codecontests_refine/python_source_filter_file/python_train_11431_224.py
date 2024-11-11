k,x = map(int,input().split())
print([x-k+1+i for i in range(2*k-1)])