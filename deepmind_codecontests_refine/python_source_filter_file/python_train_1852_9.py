N, X, Y = map(int, input().split())
K = [0]*N
for i in range(1,N+1):
	for j in range(i+1,N+1):
		K[min(min(abs(X-i)+1,abs(Y-i))+abs(j-Y),abs(i-j))-1]+=1
for i in range(N):
	print(K[i])