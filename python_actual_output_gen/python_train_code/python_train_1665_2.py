"""609C"""
# import math
def  main():
	a,b,c = map(int,input().split())
	A,B,C=-1,-1,-1
	ans = 1e9
	for i in range(1,(2*a)+1):
		for j in range(i,(2*b)+1,i):
			for k in range(2):
				cC = j*(j//c)+k*j
				res = abs(a-i)+abs(b-j)+abs(c-cC)
				if ans>res:
					ans = res
					A = i
					B = j
					C = cC
	print(ans)
	print(A,B,C)
			
	return


# main()
def test():
	t= int(input())
	while t:
		main()
		t-=1
test()