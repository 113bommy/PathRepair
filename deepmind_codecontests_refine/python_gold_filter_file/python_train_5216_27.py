import sys
def fi():
	return sys.stdin.readline()
if __name__ == '__main__':
	n = int(fi())
	l = list(map(int, fi().split()))
	prev = l[0]
	c = 1
	max1 = 0
	for i in range (1,n):
		if l[i]<= 2*prev :
			c+=1
			prev=l[i]
		else:
			prev = l[i]
			c = 1
		max1 = max(c,max1)
	max1 = max(max1,c)
	print(max1)