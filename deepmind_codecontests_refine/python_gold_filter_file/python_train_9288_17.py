import math
t=int(input())
for i in range(t):
	n,d=map(int,input().split())
	if d<=n:
		print("YES")
	else:
		m=int(pow(d,0.5))-1
		z=m+math.ceil(d/(m+1))
		#print(m)
		if z<=n:
			print("YES")
		else:
			print("NO")