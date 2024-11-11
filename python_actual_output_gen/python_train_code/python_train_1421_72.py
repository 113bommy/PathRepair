a,b,c,d = map(int,input().split())
t = max(3*a//10,a-c//250*c)
t1 = max(3*b//10,b-b//250*d)
if t > t1:
	print("Misha")
elif t1 > t:
	print("Vasya")
else:
	print("Tie")