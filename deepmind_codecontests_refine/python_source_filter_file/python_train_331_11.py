import math
n = int(input())
ans = float('inf')
if n == 1:
	print(1,1)
else:
	for i in range(1,int(n**0.5)+2):
		if n%i == 0:
			if i != n//i:
				a,b = n//i,i
				if math.gcd(a,b) == 1:
					ans = min(ans,max(a,b))
print(n//ans,ans)