a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())

#ost_n = n - (a1 + a2)
if k1 > k2:
	k1, k2 = k2, k1
	a1, a2 = a2, a1

cnt = a1 * (k1 - 1) + a2 * (k2 - 1)
if n==1 and (k1 == 1 or k2 == 1):
	print(1)
else:
	if cnt <= 0 or n-cnt <=0:
		print(0)
	else:
		print(n-cnt)
	if n < a1 * k1:
		print(int(n/k1))
	else:
		print(int(a1 + (n - a1 * k1) / k2))