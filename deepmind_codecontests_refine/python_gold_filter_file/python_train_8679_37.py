# import math
def  main():
	n = int(input())
	a = list(map(int,input().split()))
	a.sort()
	a = set(a)
	for i in range(1,3002):
		if i not in a:
			print(i)
			return
 
 
main()