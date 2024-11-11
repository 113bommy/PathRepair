import math, sys, itertools
from decimal import *

def main():
	k,a,b = map(int, input().split())
	mx = max(a,b)
	mn = min(a,b)
	
	r1 = mx%11
	r2 = mn%11
	d1 = mx//11
	d2 = mn//11
	
	if (d2==0 and r1!=0) or (d1==0 and r2!=0):
		print(-1)
		sys.exit()
	print(d1+d2)
	
			
if __name__=="__main__":
	main()
