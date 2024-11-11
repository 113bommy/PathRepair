n=int(input())
b=input()
c=input()
count=0
for i in range(n):
	print(abs(int(b[i])-int(c[i])))
	#count+=abs(int(b[i])-int(c[i]))
	if abs(int(b[i])-int(c[i])) <=5:
		count+=abs(int(b[i])-int(c[i]))
	else:
		count+=10-(abs(int(b[i])-int(c[i])))	
print(count)	
