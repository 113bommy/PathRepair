n,k=map(int,input().split())
f,t=map(int,input().split())
mx=f+min(k-t,0)
for i in range(n-1):
	f,t=map(int,input().split())
	mx=max(f-min(k-t,0),mx)
print(mx)