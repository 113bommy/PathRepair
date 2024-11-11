n,m = map(int,input().split())
s = [list(map(int,input().split())) for i in range(m)]
p = list(map(int,input().split()))
result=0
for i in range(2**n):
	flag=1
	for j in range (m):
		count=0
		for k in range (s[j][0]):
			if (i>>(s[j][k+1]-1))&1 ==1:
				count+=1
		if count%2!=p[j]:
			flag=0
	if flag==1:
		result+=1
print(result)