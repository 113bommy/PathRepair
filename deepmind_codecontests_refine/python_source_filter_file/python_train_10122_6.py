coll = int(input())
for i in range(0,coll):
	a,b = map(int,input().split())
	if a>b:
		if (a-b)%2==0:
			print(1)
		else:
			print(2)
	elif a<b:
		if b%a==0:
			print(2)
		else:
			print(1)
	else:
		print(0)