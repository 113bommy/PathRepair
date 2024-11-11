maxn=1025
luck=[0]*maxn
luck[1]=4
luck[2]=7

def return_sum(n):
	if n==0:
		return 0
	ans=0
	for i in range(maxn):
		if luck[i]<n:
			ans+=luck[i]*(luck[i]-luck[i-1])
		else:
			ans+=luck[i]*(n-luck[i-1])
			break
	return ans



l,r=map(int,input().split())
x=3

for i in range(1,512):
	luck[x]=luck[i]*10+4
	luck[x+1]=luck[i]*10+7
	print(x)
	x+=2

print(return_sum(r)-return_sum(l-1))