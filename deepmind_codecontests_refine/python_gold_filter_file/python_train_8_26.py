n=int(input())
s=input()
res1=0
res2=0
l='8'
if l not in s or n<11:
	print(0)
else:
	res1=s.count(l)
	res2=n//11
	print(min(res1, res2))