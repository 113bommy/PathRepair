n = int(input())
t= 0
r = 0
for i in range(n):
	a, b = [int(i) for i in input().split()]
	t+= a>b
	r += a<b
if t> r:
	print("Mishka")
elif r < t:
	print("Chris")
else:
	print("Friendship is magic!^^")
