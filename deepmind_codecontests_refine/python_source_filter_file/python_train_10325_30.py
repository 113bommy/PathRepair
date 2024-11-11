
size = int(input())

x = 0
s = 0
maxi = 0
x = input().split(' ')
for i in x:
	t = int(i)
	s += t
	t = max(maxi, t)


if s % 2 == 0:
	if 2 * maxi > s:
		print("NO")
	else:
		print("YES")
else:
	print("NO")


