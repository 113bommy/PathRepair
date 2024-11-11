import math
n, k = map(int, input().split())
a = []
flag = False
if n%2 != 0 :
	n += 1
	flag = True
if n//2 >= k :
	print(k*2-1)
elif n == k :
	print(n)
else :
	if flag == False :
		if k >= 10 :
			print((k-(n//2))*2)
		else :
			print((math.floor((k//2)-1)*2))
	else :
		print((math.floor(k//2)*2))