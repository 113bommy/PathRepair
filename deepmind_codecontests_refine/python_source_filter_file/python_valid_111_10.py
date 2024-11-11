N=[]
for _ in range(int(input())):
	N.append(int(input()))
for n in N:
	def rec(cs,csm,rs,re,out,n):
		if len(out)==n:
			return
		if csm<0:return
		if csm==0:
			if rs+re==0:
				out.append(cs)
				return
		if rs>0:
			ns=cs+"("
			rec(ns,csm+1,rs-1,re,out,n)
		if re>0:
			ns=cs+")"
			rec(ns,csm-1,rs,re-1,out,n)

	out=[]     
	rec("",0,2*n,2*n,out,n)
	for o in out:
		print(o)