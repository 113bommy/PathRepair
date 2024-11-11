def prime(n):
	l = []
	for i in range(2,n+1):
		flag = 0
		for j in range(2,i):
			if i % j == 0:
				flag = 1
				break
		if flag == 0:
			l.append(i)
	return l
n,k = map(int,input().split())
res = prime(n)
c = 0
for i in range(len(res)-1):
	if res[i]+res[i+1]+1 in res:
		c+=1
if c < k:
	print("NO")
else:
	print("YES")