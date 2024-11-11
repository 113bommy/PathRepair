N=int(input())
P=1
for i in range (N):
	P*=i+1
P=P%(10**9+7)
print(P)