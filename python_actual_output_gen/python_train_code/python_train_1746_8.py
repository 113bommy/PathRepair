mir1,mir2=100000000,100000000
mal1,mal2=-10000000,-10000000
n=int(input())
for i in range(n):
	l,r=map(int,input().split())
	mal1=max(mal1,l)
	mir1=min(mir1,r)
m=int(input())
for i in range(m):
	l,r=map(int,input().split())
	mal2=max(mal2,l)
	mir2=min(mir2,r)
print(max(max(mal1-mir2,mal2-mir1),0))