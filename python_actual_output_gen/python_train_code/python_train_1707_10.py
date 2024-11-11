# your code goes here
a = input()
b = input()
a = a.lstrip("0")
b =  b.rstrip("0")
if len(a) > len(b):
	print(">")
elif len(a) < len(b):
	print("<")
else:
	s = "="
	for i in range(len(a)):
		if a[i] > b[i]:
			s = ">"
			break
		elif a[i] < b[i]:
			s = "<"
			break
	print(s)	