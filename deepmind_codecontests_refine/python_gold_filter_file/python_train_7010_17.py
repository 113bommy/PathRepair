n,m = map(int,input().split())
if n == 0 and m > 0:
	print("Impossible")
	exit()
if n == 0 and m == 0:
	print(0,0)
	exit()

cpa = int(m/n)
r = (m%n)

if cpa == 0:
	min_money = n
else:
	min_money = (cpa-1)*n + r + n


max_money = max(n+m-1,n)

print(min_money,max_money)