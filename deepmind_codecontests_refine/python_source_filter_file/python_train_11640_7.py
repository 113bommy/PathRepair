n = int(input())
h = list(map(int,input().split()))

a = "Yes"
m = 0

for i in range(n):
	if h[i] - m > 1:
		a ="No"
		break
	else:
		m = max(m,h[i])
print(a)