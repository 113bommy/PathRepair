n = int(input())
x = 1
lst = []
if n == 1:
	print(n)
	print(n)
	exit()
while x < n:
	n -=x
	lst.append(x)
	x+=1

lst[-1] += n
print(x-1)
for elem in lst:
	print(elem,end=" ")
