a = int(input())
b = [i for i in range(1,a+1)]
if a<=2:print("NO")
else:
	x =a//2
	if a%2!=0:x = (a+1)//2
	b.remove(x)
	print("YES")
	print(1,x)
	print(a-1,*b)