c=0
n,m,k = map(int,input().split())
l=[]
for i in range(m+1):
	l.append(int(input()))

last=l[m]
l=l[:m]

for i in l:
	if bin(last^i).count('1')<=k:
		c+=1
print(c)