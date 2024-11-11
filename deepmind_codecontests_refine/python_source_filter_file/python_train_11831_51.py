s=input()
p=0
a=["0","2","4","6","8","a","e","i","o","u"]
for i in s:
	if i in a:
		p+=1
print(p)