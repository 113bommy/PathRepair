def prime(num):
	i=2
	while i*i<=num:
		if num%i==0:
			return False
		i+=1
	return True

p0="Ashishgup"
p1="FastestFinger"

t=int(input())
for _ in range(t):
	num=int(input())
	turn=0
	if num==1:
		print(p1)
	elif num%2!=0:
		print(p0)
	elif (num&(num-1)==0 and num>2):
		print(p1)
	elif prime(num//2) and num!=2:
		print("prime")
		print(p1)
	else:
		print(p0)
