n,m=map(int,input().split())
c=list(map(int,input().split()))
tot=c[0]
state_now=c[0]
for i in range(1,tot):
	if c[i]<c[i-1]:
		tot+=(n-c[i-1])+c[i]
	else:
		tot+=(c[i]-c[i-1])
print(tot-1)

