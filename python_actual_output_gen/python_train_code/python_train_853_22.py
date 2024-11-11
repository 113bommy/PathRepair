n = int(input())
s = input()
a = []
b = []
for i in range(0, n*2):
	if(i < n):
		a.append(int(s[i]))
	else:
		b.append(int(s[i]))

a.sort()
b.sort()

ans = "YES"
for i in range(1, len(a)):
	if((a[i] - b[i])*(a[0] - b[0]) <= 0):
		ans = "NO"
		break

print(ans)

