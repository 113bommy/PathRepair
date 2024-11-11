a = [] 
for i in range(4):
	a.append(int(input()))
a,b,c,d = a 
f = (a==d and c == 0) or (a > 0 and d > 0 and c > 0 and a==d)  
if f:
	print(1)
else:
	print(0)