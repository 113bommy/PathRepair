for _ in range(int(input())):
	a,b,c,d = map(int,input().split())
	ans = ['','','','']
	if (a+b)%2==1:
		ans[2] = 'Tidak'
		ans[3] = 'Tidak'
		if a+d>0 and b+c>0:
			ans[0] = 'Ya'
			ans[1] = 'Ya'
		elif a+d==0 and b+c>0:
			ans[0] = 'Tidak'
			ans[1] = 'Ya'
		elif a+d>0 and b+c==0:
			ans[0] = 'Ya'
			ans[1] = 'TIdak'
	else:
		ans[0] = 'Tidak'
		ans[1] = 'TIdak'
		if a+d>0 and b+c>0:
			ans[2] = 'Ya'
			ans[3] = 'Ya'
		elif a+d==0 and b+c>0:
			ans[3] = 'Tidak'
			ans[2] = 'Ya'
		elif a+d>0 and b+c==0:
			ans[3] = 'Ya'
			ans[2] = 'TIdak'
	print(*ans)