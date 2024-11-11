for j in range(int(input())):
	a,b,c,r = map(int,input().split())
	if a>b:
		d = b
		b = a
		a = d
	ans = 0
	if c+r< a or c-r > b:
		print(b-a)
		continue
	else:
		if c+r > a and c-r < a and c+r<b :
			# print("oo")
			# print(b,c,r)
			ans = (b-c-r)
		elif c-r > a and c+r<b :
			# print("dfs")
			ans = (b-a-2*r)
		# elif c+r > b and c-r < b and c-r >a:
		else:	
			ans = (c-r-a)
	if ans < 0:
		print(0)
	else:
		print(min(ans,b-a))


