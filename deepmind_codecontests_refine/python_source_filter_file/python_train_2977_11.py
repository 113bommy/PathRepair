import math
n, k = map(int, input().split())
if k == 1:
	print(n)
	exit(0)
a, k = [], k - 1 
for i in range(2, math.ceil(math.sqrt(n))):
    while n % i == 0:
        a.append(i)
        k -= 1
        n //= i
        if k == 0:
            if n == 1:
            	print(-1)
            else:
            	print(*a, n)
            exit(0)
print(-1)