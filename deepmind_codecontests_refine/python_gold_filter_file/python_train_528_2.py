q = int(input())

for i in range(q):
	s = input().split(" ")
	n,m,k = abs(int(s[0])),abs(int(s[1])),int(s[2])
	x,y = min(n,m),max(n,m)
	if(k<y):
		print("-1")
	else:
		res = x
		k -= x
		y -= x
		if y == 0:
			if(k)%2 == 1:
				k -= 1
				res -= 1
			res += k
		else:
			
			if (k-y)%2 == 0:
				res += k-y%2
			else:
				res += 1
				k -= 2
				y -= 1
				res += k-y%2


		print(res)