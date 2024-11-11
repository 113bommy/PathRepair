for _ in range(int(input())):
	n = int(input())
	s = 'abcdefghijklmnopqrstuvwxyz'
	if(n<27):
		print(s[:n])
	else:
		if(n%2 == 0):
			k = n//2
			ans = ''
			for i in range(n):
				if(i == k):
					ans= ans+'a'
				else:
					ans = ans + 'z'
		else:
			k = (n-3)//2
			ans = 'z'*k
			ans = ans + 'aaba'
			a = 'z'*(k-1)
			ans = ans + a
			

		print(ans)


			
