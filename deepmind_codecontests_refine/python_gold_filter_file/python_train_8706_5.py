ar =  list(map(int,input().split()))
ar.sort()
a, b, c = ar[0], ar[1], ar[2]
if a == 1 or b == 1 or c == 1:
	print("YES")
elif a==b==2 or a==c==2 or b==c==2:
	print("YES")
elif a==b==c==3:
	print("YES")
elif a == 2 and b == c == 4:
	print("YES")
else:
	print("NO")
