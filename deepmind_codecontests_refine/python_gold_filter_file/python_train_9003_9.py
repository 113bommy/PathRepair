try:
	n = int(input())
	cnt = 1
	while n>1:
		if n%2==1:
			cnt+=1
			n-=1
		n//=2
	print(cnt)
except:
	pass