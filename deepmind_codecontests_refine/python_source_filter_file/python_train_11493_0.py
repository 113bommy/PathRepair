n, m=list(input().split())
n=int(n)
m=int(m)
l=[{i} for i in range(1, n+1)]

for i in range(m):
	a, b=list(map(int, input().split()))
	fa=False
	fb=False
	for j in l:
		if a in j:
			fa=True
			x=l.index(j)
			l[l.index(j)]|={a, b}
		if b in j:
			y=l.index(j)
			fb=True
			l[l.index(j)]|={a, b}
	if fb and fa and y!=x:
		l[x]|=l[y]
		l.remove(l[y])
y={tuple(i) for i in l}
l=[set(i) for i in y]
ll=[len(i) for i in l]
f=True
for i in ll:
	if i>3:
		print(-1)
		f=False
		break
print(l)
if f:
	p=[]
	if ll.count(1)<ll.count(2) or (ll.count(1)-ll.count(2))%3!=0: print(-1)
	else:
		while len(l)>0:
			for i in l:
				if len(i)==3:
					print(' '.join(map(str, i)))
					l.remove(i)
				elif len(i)==1:
					if len(p)==2:
						print(' '.join(map(str, p+list(i))))
						p=[]
						l.remove(i)
				elif len(i)==2:
					if len(p)==0:
						p+=list(i)
						l.remove(i)
			if all (len(i)==1 for i in l) and len(l)%3==0:
				c=0
				for i in range(len(l)):
					if c in {0, 1}:
						print(' '.join(map(str, l[i])), end=' ')
						c+=1
					else:
						print(' '.join(map(str, l[i])))
						c=0
				break






