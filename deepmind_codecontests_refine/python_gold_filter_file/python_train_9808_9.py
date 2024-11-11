"""609C"""
# import math
# import sys
def  main():
	a,b,c = map(int,input().split())
	mx = max(a,max(b,c))
	mn = min(a,min(b,c))
	if abs(mx-mn)<=2:
		print(0)
	else:
		print((abs(mx-mn)-2)*2)
			
	return

# main()
def test():
	t= int(input())
	while t:
		main()
		t-=1
test()