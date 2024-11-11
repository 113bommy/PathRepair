n=int(input())
m=2*n
for i in range (n):
	if i*(i+1)==m:
		print("YES")
		break
else :
	print("NO")