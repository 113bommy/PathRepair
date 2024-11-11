n, d = map(int,input().split())   # co-ordinates of corn field
m = int(input())   # no of grasshopper
for i in range(m):
	a,b = map(int,input().split())
	eqn1 = a+b-d
	eqn2 = -a+b-d
	eqn3 = a+b-2*n+d
	eqn4 = -a+b+d
	
	if eqn1 >= 0 and eqn2 <= 0 and eqn3 <= 0 and eqn4 >= 0 :
		print("YES")
	else :
		print("NO")