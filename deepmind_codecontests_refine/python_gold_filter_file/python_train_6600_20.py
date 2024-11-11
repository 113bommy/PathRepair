def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input().split()))

# Recursive function to return gcd of a and b
def gcd(a,b):
	
	# Everything divides 0 
	if (b == 0):
		return a
	return gcd(b, a%b)


a,b,c,d = I()


if (a/b)==(c/d):
	print(str(0)+'/'+'1')
else:
	if (a*d)-(c*b)>0:
		print(str(int((-(b*c)+(a*d))/gcd((-(b*c)+(a*d)),(a*d))))+'/'+str(int(a*d/gcd((-(b*c)+(a*d)),(a*d)))))
	if (b*c)-(a*d)>0:
		print(str(int(((b*c)-(a*d))/gcd(((b*c)-(a*d)),(b*c))))+'/'+str(int(b*c/gcd(((b*c)-(a*d)),(b*c)))))

