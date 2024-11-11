n = int(input())
tota = 0
totb = 0
for i in range(n):
	a , b = map(int , input().split())
	tota += a
	totb += b
print(min(tota , (n - tota) + max(totb , (n - totb))))