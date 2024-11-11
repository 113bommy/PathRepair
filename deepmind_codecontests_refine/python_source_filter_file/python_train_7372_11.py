from itertools import product
d,g = (int(i) for i in input().split())
p = [[int(i) for i in input().split()] for i in range(d)]
q,ans = [],10000
for i in range(d): q.append(p[i][0]*(i+1)*100+p[i][1]) 
for i in product(range(2), repeat=d):
	m,n,x = 0,0,[]
	for j in range(d):
		if i[j]==1: m,n = m+q[j],n+p[j][0]
		else: x.append(j)
	if m>=g: ans = min(ans,n)
	else:
		for k in x:
			num = (g-m+99)//((k+1)*100)
			if num<p[k][0]: ans = min(ans,n+num)
print(ans)