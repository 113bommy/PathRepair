n=input()
s=""
w=""
if len(n)&1:
	f=0
	for i in range(len(n)//2):
		f=1
		s+=n[i]
		w+=n[len(n)-i-1]
	if f==0:
		print(n)
	else:
		print((w+n[len(n)//2]+s))
else:
	for i in range(len(n)//2):
			s+=n[len(n)-i-1]
			s+=n[i]

	print(s[::-1])