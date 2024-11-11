for o in range(int(input())):
	l ,r = map(int,input().split())
	a = max(l,r) + 1
	if l%a>=a//2 and r%a>=a//2:
		print("YES")
	else:
		print("NO")