modulo = 10**9+7

n, x, pos = map(int, input().split())
bigger = 0
smaller = 0
l ,r = 0, n
while l < r:
	mid = (l+r)//2
	if mid > pos:
		r = mid
		bigger += 1
	elif mid < pos:
		l = mid+1
		smaller += 1
	else:
		l = mid+1
res = 1
for i in range(smaller):
	res *= x-1-i
	res %= modulo
for i in range(bigger):
	res *= (n-x)-i
	res %= modulo
for i in range(n-bigger-smaller-1):
	res *= (i+1)
	res %= modulo
print(res)