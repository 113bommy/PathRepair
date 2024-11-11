import math, sys

def pir(d,k1,k2):
	r1= 0
	r2 = 0
	if k1*(d-k1-1)>0:
		r1 = k1*(d-k1-1)
	if k2*(d-k2-1)>0:
		r2 = k2*(d-k2-1)
	t1 = (k1+1)*k1//2
	t2 = k2*(k2+1)//2
	if d<=k1:
		t1 = d*(d-1)//2
	if d<=k2:
		t2 = d*(d-1)//2
	return (t1 + d + t2 + r1 + r2)
	
def main():
	n,m,k = map(int, input().split())
	r = m-n
	k1 = k-1
	k2 = n-k
	left = 0
	right = r
	while(left!=right):
		middle = (left+right)//2
		eq = pir(middle, k1, k2)
		eq2 = pir(middle+1, k1, k2)
		print(middle, eq, eq2, r,left, right)
		if eq2>r>=eq:
			left = middle
			break
		if eq>r:
			right = middle
		else:
			left = middle+1
	print(left+1)
		
		
		
		 
			

if __name__=="__main__":
	main()
