n = int(input())
s = input().split(" ")
a = 0
b = 0
for i in s:
	if (int(i)%2 == 1):
		a+=1
	else:
		b+=1
if a < b:
	print(a)
else:
	print(b+(a-b)//3)