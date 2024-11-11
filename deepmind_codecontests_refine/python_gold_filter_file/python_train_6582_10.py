'''input
20 20 40
'''	
fact=[1]*61
for i in range(1,61):
	fact[i]=fact[i-1]*i
def ncr(n,r):
	return (fact[n]//(fact[n-r]*fact[r]))
b,g,t=map(int,input().strip().split(' '))
ans=0
for i in range(4,t):
	#print(i,t-i,ncr(b,i),ncr(g,t-i))
	ans+=(ncr(b,i)*ncr(g,t-i))
print(ans)