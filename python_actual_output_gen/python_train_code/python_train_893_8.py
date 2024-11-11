#http://codeforces.com/problemset/problem/459/A
inp = list(map(int, input().split() ))
x1,y1 = inp[0],inp[1]
x2,y2 = inp[2],inp[3]

if x1==x2:
	const = abs(x1-x2)
	print(x1+const,y1 , x1+const, y2)	
elif y1==y2:
	const = abs(y1-y2)
	print(x1, y1+const, x2, y2+const)
elif abs(x2-x1) == abs(y2-y1):
	print(x1,y2,x2,y1)
else:
	print(-1)