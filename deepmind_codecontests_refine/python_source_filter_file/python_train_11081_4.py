a=input()[2:]
b=input()[2:]
c=input()[2:]
d=input()[2:]
di={}
di[a]='A'
di[b]='B'
di[c]='C'
di[d]='D'
l=[a, b, c, d]
l.sort(key=lambda x : len(x))
good1, good2=0, 0
if 2*len(l[0])<=len(l[1]) :
	good1+=1
elif len(l[3])>=2*len(l[2]) :
	good2+=1
if good1 and good2:
	print('C')
elif good1 and not good2:
	print(di[l[0]])
elif not good1 and good2:
	print(di[l[3]])
else:
	print('C')