n,k,s=list(map(int,input().split())),0
for i in range(k,n+2):
	s+=i*(n+n-(i-1))//2+1-(i*(i-1))//2
print(s%(1000000007))