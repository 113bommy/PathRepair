t=int(input())
p=list(map(int,input().split()))
q=list(set(p))
mo=len(q)
ins=0
if(t==2):
	print(ins)
else:
	po=max(p)
	pi=min(p)
	l=p.count(po)
	m=p.count(pi)
	if(l>1 and m>1):
		ins=po-pi
	elif(l==1 and m>1):
		ins=q[mo-2]-pi
	elif(m==1 and l>1):
		ins=po-q[1]
	elif(m==1 and l==1):
		ins=min(po-q[1],q[mo-2]-pi)
	print(ins)
		