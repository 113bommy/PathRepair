n=int(input())
l=list(map(int,input().split()))
m=int(input())
_l=list(map(int,input().split()))
mark = [False for x in range(n)]
i=0
j=0
cs = 0
ok=True
while(i<n and j<m):
	cs += l[i]
	if(cs==_l[j]):
		mark[i]=True
		j+=1
		cs=0
	elif(cs>_l[j]):
		ok=False
		break
	i+=1
if(ok==False):
	print("NO")
	exit(0)
a = []
al = []
i=0
j=0
while(i<n):
	if(mark[i]==True):
		a.append(l[j:i+1])
		al.append(i+1-j)
		j=i+1
	i+=1
if(mark[n-1]==False):
	a.append(l[j:])
	al.append(n-j)
	j=i+1
ok=True
n=len(a)
if(n!=m):
	print("NO")
	exit(0)
for i in range(n):
	l=a[i]
	m=al[i]
	j=0
	sok=False
	if(m==1):
		sok=True
	while(j<m-1):
		if(l[j]!=l[j+1]):
			sok=True
			break
		j+=1
	if(sok==False):
		ok=False
		break
if(ok==False):
	print("NO")
	exit(0)
print("YES")
for i in range(n):
	l=a[i]
	m=al[i]
	for j in range(m-1):
		mx=0
		midx=-1
		lenl = m-j
		for k in range(lenl):
			if(l[k]>mx):
				if(k==0):
					if(l[k+1]!=l[k]):
						mx=l[k]
						midx=k
				elif(k==lenl-1):
					if(l[k-1]!=l[k]):
						mx=l[k]
						midx=k
				else:
					if(l[k-1]!=l[k] or l[k]!=l[k+1]):
						mx=l[k]
						midx=k
		if(midx==0):
			l[0] += l[1]
			del l[1]
			print(str(i+1)+" R")
		elif(midx==lenl-1):
			l[midx] += l[midx-1]
			del l[midx-1]
			print(str(i+midx+1)+" L")
		else:
			if(l[midx-1]!=l[midx]):
				l[midx] += l[midx-1]
				del l[midx-1]
				print(str(i+midx+1)+" L")
			else:
				l[midx] += l[midx+1]
				del l[midx+1]
				print(str(i+midx+1)+" R")

