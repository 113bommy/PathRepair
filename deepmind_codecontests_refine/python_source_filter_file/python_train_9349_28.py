K,A,B = map(int,input().split())
a = 1+K
K = K-A-1
if K % 2 == 0:
	b = A+(B-A)*(int(K/2))
else:
	b = A+(B-A)*(int(K/2))+1

print(max(a,b))