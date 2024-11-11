n=int(input())
l=list(map(int,input().split()))
d1,d2,x,temp={},{},'10',[1]
for i in range(len(l)):
	try:
		d1[l[i]].append(i)
	except:
		d1.update({l[i]:[]})
		d1[l[i]].append(i)
while len(x)<=32:
	temp.append(int(x,2))
	x=x+'0'
for i in range(len(l)):
	if l[i]!=-1:
		x=l[i]
		for j in range(len(temp)):
			try:
				y=abs(temp[j]-x)
				if x+y==temp[j]:
					if x==y:
						if len(d1[y])>1:
							for k in range(len(d1[y])):
								l[d1[y][k]]=-1
							for k in range(len(d1[x])):
								l[d1[x][k]]=-1
							break
					else:
						if len(d1[y])>0:
							for k in range(len(d1[y])):
								l[d1[y][k]]=-1
							for k in range(len(d1[x])):
								l[d1[x][k]]=-1
							break	
			except:
				pass
c=0
for i in l:
	if i!=-1:
		c+=1
print(c)