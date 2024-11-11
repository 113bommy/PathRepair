n, m = map(int,input().split())

mn = 4*60
mn -= m 
p = 0
for x in range(1,n+1):
	if mn - x*5 >= 0:
		mn -= x*5
		p += 1
	else: break

print(p)