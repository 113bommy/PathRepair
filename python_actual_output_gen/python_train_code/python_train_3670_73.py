'''input
512 4

'''
inp = input()
n = int(inp[0])
k = int(inp[1])
while k > 0:
	k-=1
	if (n % 10 != 0):
		n-=1
	else:
		n /= 10
print (int(n))
