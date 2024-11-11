s = input().split()
n=int(s[-1])
val = 0
sign = 1
ls = []
for c in s[:-2]:
	if c == '+': sign = 1
	elif c == '-': sign = -1
	elif c == '?': 
		ls.append(sign)
		val+=sign
	else:
		print(c)
for i in range(len(ls)):
	if val > n:
		if ls[i]>0: continue
		ls[i]-= min(n-1, val-n)
		val-= min(n-1, val-n)
	elif val < n:
		if ls[i]<0: continue
		ls[i]+=min(n-1,n-val)
		val+=min(n-1,n-val)
if val != n:
	print("Impossible")
else:
	print("Possible")
	print("".join([(" + " if v>0 else " - ")+str(abs(v)) for v in ls])[3:]+" = "+str(n))
