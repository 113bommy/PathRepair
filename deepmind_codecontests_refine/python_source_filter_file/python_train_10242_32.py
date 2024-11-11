from sys import stdin
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())

v=[]
for _ in range(3):
	v+=[mp()]
k=[[0 for _ in range(3)] for _ in range(3)]
for i in range(3):
	for j in range(3):
		if i==0 :
			if j==0:
				k[i][j]+=v[i][j+1]+v[i+1][j]+v[i][j]
			elif j==1:
				k[i][j]=v[i][j-1]+v[i][j+1]+v[i+1][j]+v[i][j]
				# print(v[i][j])
			else:
				k[i][j]+=v[i][j-1]+v[i+1][j]+v[i][j]
		elif i==1:
			if j==0:
				k[i][j]+=v[i][j+1]+v[i+1][j]+v[i-1][j]+v[i][j]
			elif j==1:
				k[i][j]+=v[i][j-1]+v[i][j+1]+v[i+1][j]+v[i-1][j]+v[i][j]
			else:
				k[i][j]+=v[i][j-1]+v[i+1][j]+v[i-1][j]+v[i][j]
		else:
			if j==0:
				k[i][j]+=v[i][j+1]+v[i-1][j]+v[i][j]
			elif j==1:
				k[i][j]+=v[i][j-1]+v[i][j+1]+v[i-1][j]+v[i][j]
			else:
				k[i][j]+=v[i][j-1]+v[i-1][j]+v[i][j]
# print(k)
for i in range(3):
	for j in range(3):
		if k[i][j]&1:
			k[i][j]=0
		else:
			k[i][j]=1
for i in range(3):
	print(*k[i])