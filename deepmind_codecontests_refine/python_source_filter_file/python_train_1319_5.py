# import math
def  main():
	a,b = map(int,input().split())
	mx = max(a,b)
	if mx==6:
		print("1/6")
	elif mx==5:
		print("2/6")
	elif mx==4:
		print("1/2")
	elif mx == 3:
		print("2/3")
	elif mx==2:
		print("5/6")
	else:
		print("1/6")
		


main()