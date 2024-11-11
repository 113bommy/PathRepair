"""609C"""
# import math
def  main():
	n,k = map(int,input().split())
	cnt = 0

	for _ in range(n):
		temp = 0
		number = str(input())
		num = list(number)
		num.sort()
		for x in num:
			if int(x)==temp:
				temp+=1
		if k==temp-1:
			cnt+=1
	print(cnt)
 
 
main()



# t= int(input())
# while t:
# 	main()
# 	t-=1




# Octahedron. Octahedron has 8 triangular faces.
# Dodecahedron. Dodecahedron has 12 pentagonal faces.
# Icosahedron