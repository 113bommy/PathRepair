n = int(input())
a = 1234567
b = 123456
c = 1234
x = n//a
for i in range(1,x+1):
	xx = n-i*a
	y = xx//b
	for j in range(1,y+1):
		z = n- (a*i + j*b)
		if z %c == 0:
			print ("YES")
			exit()
print ("NO")