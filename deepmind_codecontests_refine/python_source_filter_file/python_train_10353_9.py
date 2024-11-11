o=[]
x=[]
ans=0
n,v=map(int,input().split())
for i in range(n):
	k={}
	a,*l=list(map(int,input().split()))
	k[a]=l
	# print(k)
	o.append(k)
# print(o)
q=0
for i in o:
	q+=1
	# print(i.keys())
	for j in i.values():
		# print(j)
		for t in j:
			# print(t)
			if t<v:
				ans+=1
				# for t in i.keys():
				# 	x.append(t)
				if q not in x:
					x.append(q)


print(ans)
print(*x)