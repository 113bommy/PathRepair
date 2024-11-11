def digits(n):
	cur = 0
	while(n != 0):		
		cur += n % 10
		n //= 10
	return cur
		

n = int(input())
ans = set()
for i in range(100):
	if(n - i > 0 and digits(n-i) == i):
		ans.add(n-i)
print(len(ans))
for x in ans:
	print(x, end = ' ')
		
