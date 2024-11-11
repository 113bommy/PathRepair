n=int(input())
l=[]
for i in range(n):
	str=input()
	l.append(str[:n])
print(l)
ct=0
for i in range(1,n-1):
	for j in range(1,n-1):
		if l[i][j]=='X' and l[i-1][j-1]=='X' and l[i-1][j+1]=='X' and l[i+1][j+1]=='X' and l[i+1][j-1]=='X':
			ct+=1
print(ct)