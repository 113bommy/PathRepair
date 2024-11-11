n = int(input())
b = 3
for i in range(n):
	a = int(input())
	if a==b:
		print("NO")
		exit(0)
	else:
		b-=a
print("YES")
