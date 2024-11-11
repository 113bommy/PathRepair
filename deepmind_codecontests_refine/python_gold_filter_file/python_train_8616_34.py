def comb(n,r,m):
	if r == 0: return 1
	return memf[n]*pow(memf[r],m-2,m)*pow(memf[n-r],m-2,m)
def memfact(a):
	temp = 1
	yield temp
	for i in range(1,a+1):
		temp = temp * i % 1000000007
		yield temp

K = int(input())
S = input()
s = len(S)
ans = 0
m = 1000000007
memf = []
for x in memfact(s+K-1):
	memf.append(x)
for i in range(K+1):
	ans = (ans+comb(s+K-i-1,K-i,m)*pow(25,K-i,m)*pow(26,i,m)) % m
print(ans)