n=int(input())
m=list(map(int,input().split()))
k=[]
for i in range(1,n+1):
	k.append(i)
print(len(set(k)-set(m)))