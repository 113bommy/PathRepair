n = int(input())
parity = 0
s1, s2 = 0, 0
for _ in range(n):
	a,b = map(int, input().split())
	s1 += a
	s2 += b
	if(a % 2 == 0 and b%2 != 0):
		parity+=1
	if(a%2 != 0 and b%2 == 0):
		parity+=1

if(s1 % 2 == 0 and s2 % 2 == 0):
	print(0)
if(s1 % 2 == 0 and s2 % 2 == 0):
	if(parity):
		print(1)
	else:
		print(-1)
else:print(-1)
