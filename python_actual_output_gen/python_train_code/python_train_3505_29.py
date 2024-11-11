A,B,C,X= [int(input()) for x in range(4)] 
ans = 0
for a in range(0,A):
	for b in range(0,B):
		for c in range(0,C):
			if 500*a+100*b+50*c == X:
				ans += 1
print(ans)