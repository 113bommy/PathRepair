def ret(n,k,t):
	if t<k:
		return t
	elif t>=k and t<=2*k:
		return k
	else:
		return 3*k-t
n,k,t=map(int,input().split())
print(ret(n,k,t))