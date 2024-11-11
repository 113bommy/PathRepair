k,n,w=map(int,input().split())
amount=int(((1+w)*w/2)*k)
if amount>n:
	borrow=amount-n
	print(int(borrow))
else:
	print('()')