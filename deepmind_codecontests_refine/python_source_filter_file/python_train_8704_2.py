n = int(input())
while (n%10==0):
	n = n/10
n = str(n)
if n[::-1]==n:
	print("YES")
else:
	print("NO")