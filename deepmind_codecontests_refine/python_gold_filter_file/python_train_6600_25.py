def gcd(a,b):
	if a==0:
		return b
	else: 
		return gcd(b%a,a)



def main():
	a,b,c,d = map(int,input().split())
	if a/b<c/d:
		# ans = (bc-ad)/bc
		print(f"{(b*c-a*d)//gcd((b*c-a*d),(b*c))}/{(b*c)//gcd((b*c-a*d),(b*c))}")
	elif a/b>=c/d:
		print(f"{(a*d-b*c)//gcd((a*d-b*c),(a*d))}/{(a*d)//gcd((a*d-b*c),(a*d))}")
	# else:
	# 	print(0)



main()