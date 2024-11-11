n,m,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)
if len(a)==1:
	print(k*a[0])
else:
	p=m//(k+1)
	w=p*((a[0]*k)+a[1])
	if m%(k+1)==0:
		print(w)
	else:
		print(w+(m%(k+1))*k)