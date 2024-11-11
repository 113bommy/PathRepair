a,b,c = map(int,input().split())

if c == 0:
	print("YES" if a==b else "NO")
	exit()
elif c < 0:
	a,b,c = -a,-b,-c
print("YES" if b>a and (b-a)%c == 0 else "NO")