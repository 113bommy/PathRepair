a,b,c,d = map(int, input().split())
 
if a + b > c and a + c > b and b + c > a:
	print("TRIANGLE")
elif d + b > c and d + c > b and b + c > d:
	print("TRIANGLE")
elif a + d > c and a + c > d and d + c > a:
	print("TRIANGLE")
elif a + b > d and a + d > b and b + d > a:
	print("TRIANGLE")
elif a+b == c or a+c==b or b+c==a:
    print('SEGMENT')
elif d+a==c or a+c==d or d+c==a:
    print('SEGMENT')
elif b+d==c or d+c==b or b+c==d:
    print('SEGMENT')    
elif b+d==c or d+c==b or b+c==d:
    print('SEGMENT')
else:
	print("IMPOSSIBLE")