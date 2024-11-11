from math import gcd
def help():
	ans = []
	a,b = map(int,input().split(" "))
	if(gcd(a,b)>1):
		print("Impossible")
		return
	while a!=1 or b!=1:
		if(a==1):
			ans.append(str(b-1)+"B")
			break
		elif(b==1):
			ans.append(str(a-1)+"A")
			break
		elif(a>b):
			ans.append(str(a//b)+"A")
			a = a%b
		elif(b>a):
			ans.append(str(b//a)+"B")
			b = b%a
	print(*ans[::-1],sep="")
help()