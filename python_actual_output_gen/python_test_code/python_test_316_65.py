s=input()
res=0
for m in s:
	if m in ['0','2','4','6','8']:
		res+=1
	elif m in ['a', 'e', 'i', 'o','u']:
		res+=1
print(res)