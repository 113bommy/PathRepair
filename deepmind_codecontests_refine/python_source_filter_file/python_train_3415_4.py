N,L = map(int,input().split())
l = list(map(lambda x : L+x+1 , range(1,N+1)))
print(sum(l)-min(l,key=abs))