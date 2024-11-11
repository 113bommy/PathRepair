"""609C"""
# import math
# import sys
def main():
	# n ,m= map(int,input().split())
	# a = list(map(int,input().split()))
	n,X,Y = map(int,input().split())
	cntx,cntnegx,cnty,cntnegy = 0,0,0,0
	for _ in range(n):
		x,y = map(int,input().split())
		if x<X:
			cntnegx+=1
		elif x>X:
			cntx+=1
		if y<y:
			cntnegy+=1
		elif y>y:
			cnty+=1
	
	mx = max(cnty,cntx,cntnegy,cntnegx)
	print(mx)
	# print(cntx,cnty,cntnegx,cntnegy)
	if mx == cntx:
		print(X+1,Y)
	elif mx==cnty:
		print(X,Y+1)
	elif mx == cntnegx:
		print(X-1,Y)
	else:
		print(X,Y-1)
	return


main()
# def test():
# 	t = int(input())
# 	while t:
# 		main()
# 		t-=1
# test()
