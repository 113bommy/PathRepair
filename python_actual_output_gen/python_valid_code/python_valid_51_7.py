[a,x,y] = [int(i) for i in input().split()]


if y % a == 0:

	print(-1)
	exit()


n = y//a

if n==0 or n%2 :
	if abs(x) >= a/2:
		print(-1)
	elif n==0:
		print(1)
	else:
		print(2 + 3 * (n//2))

else:
	if x==0 or abs(x) >= a/2:
		print(-1)
	elif x<0:
		print(3 * (n//2))
	else:
		print(1 + 3 * (n//2))
