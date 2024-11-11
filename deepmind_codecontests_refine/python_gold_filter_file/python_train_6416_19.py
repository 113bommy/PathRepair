a = int(input())
b = a//10
s = str(b + (int((a%10)+5)//10))
if a >= 5:
	print(s + '0')
else :
	print(s)