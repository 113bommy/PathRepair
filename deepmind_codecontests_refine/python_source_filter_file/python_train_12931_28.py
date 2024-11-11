n,m=input().split()
n=int(n)
m=int(m)
l=input().split()
o=input().split()
ll=len(l)
oo=len(o)
if ll==n and oo==m:
	q=int(input())
	for i in range(q):
		y=int(input())
		x=y-1
		if n==m:
			if y<=n:
				print(l[x],o[x])
			if y>n:
				a=(y%n)-1
				print(l[a],o[a])
		elif n>m:
			if y<=m:
				print(l[x],o[x])
			elif y>m and y<=n:
				a=(y%m)-1
				print(l[x],o[a])
			elif y>n:
				a=(y%n)-1
				b=(y%m)-1
				print(l[a],o[b])
		elif n<m:
			if y<=n:
				print(l[x],o[x])
			elif y>n and y<=m:
				a=(y%n)-1
				print(l[a],o[x])
			elif y>m:
				a=(y%n)-1
				b=(y%m)-1
				print(l[a],o[b])