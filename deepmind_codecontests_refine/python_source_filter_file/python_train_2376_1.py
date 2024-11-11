n,m=map(int,input().split())
a=[]
for i in range(n):
	k=list(map(int,input().split()))
	a.append(k)
q=[]
for i in range(n):
	for j in range(m):
		if a[i][j]%2!=0:
			a[i][j]-=1
			if j!=m-1:
				a[i][j+1]+=1
				q.append([i+1,j+1,i+1,j+1+1])
			else:
				try:
					a[i+1][j]+=1
					q.append([i+1,j+1,i+1+1,j+1])
				except:
					print(len(q))
					for ii in range(len(q)):
						print(*q[ii])
						exit()
print(len(q))
for i in range(len(q)):
	print(*q[i])
