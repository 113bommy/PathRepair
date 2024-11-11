N = int(input())
x,r = 1,0

while x*x <= N:
	if N%x==0:
		if x>1 and N//(x-1)==N%(x-1):
			r += x-1
		t = N//x-1
		if N//t==N%t:
			r += t
	x += 1

print(r)