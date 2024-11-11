n,a,b=map(int,input().split())
s=list(map(int,input().split())
t=0
for i in range(n-1):
	t+=min(b,a*(s[i+1]-s[i]))

print(t)