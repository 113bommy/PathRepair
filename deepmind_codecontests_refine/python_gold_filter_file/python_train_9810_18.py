t = int(input())
for i in range(t):
	n = int(input())
	s = input()
	diff = 1
	ans= s
	for i in range(0,n):
		if((n-i)%2 == 0):
			x = s[i:] + s[:i]
		else:
			x = s[i:] + s[:i][::-1]
		if(x < ans):
			diff = i+1
			ans = x

	print(ans)
	print(diff)