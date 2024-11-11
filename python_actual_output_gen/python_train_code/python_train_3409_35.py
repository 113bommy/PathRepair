a,b = map(int,input().split())
if a > b:
	if b%2 == 1:
		print(b//2)
	else:
		print(b//2-1)
elif a < b//2:
	print(0)
elif a > b//2 and a < b:
	if b%2 == 1:
		print(b//2-b+a+1)
	else:
		print(b//2-b+a)
else:
	if b%2 == 0:
		print(b//2-1)
	else:
		print(b//2)
