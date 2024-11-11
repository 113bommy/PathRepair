import sys
n, m, d = map(int, input().split())
d -= 1
mas = list(map(int, input().split()))
best = (n - sum(mas)) // (m + 1)
kol = (n - sum(mas)) % (m + 1)
now = best
if kol != 0:
	now += 1
if (now > d):
	print ("NO")
	sys.exit(0)

print ("YES")
for i in range(m):
	if i < kol:
		print ('0 ' * (1 + best), end = '')
	else:
		print ('0 ' * best, end = '')
	print ((str(i + 1) + ' ') * mas[i], end = '')
print ('0 ' * best)
