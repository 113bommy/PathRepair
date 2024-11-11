n = int(input())
res = 0
for i in range(1,n+1):
	k = n//i
	res += i*(k*(k+1)//2)
print(res)