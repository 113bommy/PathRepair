t = int(input())
for i in range(t):
	n = int(input())
	s = input()
	ans = 'z'*n
	val=-1
	for k in range(1,n+1):
		if(k==n):
			tmp = s[::-1]
		else:
			ss = s[:k-1]
			if (n%2 != k%2):
				tmp = s[k-1:]+ss
			else:
				tmp = s[k-1:]+ ss[::-1]
		# print(k,tmp, k%2 == n%2)
		
		if(ans > tmp):
			ans = tmp
			val = k
	print(ans)
	print(val)
