import math
import sys

array=list(map(int,input().split()))
n = array[0]
k = array[1]

maxi = -1
for i in range(1, int(math.sqrt(n)) + 1):
	if n % i != 0:
		continue
	del1 = i
	del2 = n / i

	sum1 = del1 * k * (k - 1) / 2
	sum2 = del2 * k * (k - 1) / 2

	if n - sum1 > (k - 1) * del1:
		maxi = max(maxi, del1)

	if n - sum2 > (k - 1) * del2:
		maxi = max(maxi, del2)

if maxi == -1:
	print(-1)
	sys.exit()

sum = 0
ans = []
for i in range(1, k):
	ans.append(int(i * maxi))
	sum += i * maxi

ans.append(n - sum)
print(" ".join(map(str,ans)))	
	
	
