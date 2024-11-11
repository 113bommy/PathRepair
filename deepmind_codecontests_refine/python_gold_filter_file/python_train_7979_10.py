n,m=map(int,input().split())
a=list(map(int,input().split()))
t=[0]*n
for p in a:
	t[p-1]+=1
print(min(t))