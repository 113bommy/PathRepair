n,v = list(map(int, input().split()))
litres = 0
price = 0
litres1 = 0
fill = 0
chuj = 1
if n-1 < v:
	print(n-1)
else:
	price = v
	for i in range(2,n):
		if n-i < v:
			print(price)
			chuj = 0
			break
		price = price + i
if chuj ==1:
	print(price)