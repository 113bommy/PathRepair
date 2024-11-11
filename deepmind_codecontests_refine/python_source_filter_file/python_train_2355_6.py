import sys
n, x = map(int, input().split())
pw1 = 1 << 17
pw2 = 1 << 18
if n == 1:
	print("YES\n", x)
elif n == 2 and x == 0:
	print("NO")
elif n == 2:
	print("YES\n", x)
else:
	ans = 0
	print("YES")
	for i in range (1, n - 2):
		sys.stdout.write(str(i) + " ")
		ans ^= i
	if ans == x:
		print(pw1 + pw2, pw1, pw2)
	else:
		print(pw1, ((pw1 ^ x) ^ ans), "0")