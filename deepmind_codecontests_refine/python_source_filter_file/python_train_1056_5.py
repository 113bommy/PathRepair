x=int(input())
s=[n for n in input()]
l=0
for n in s:
	if n=='-' and l<0:
		l-=1
	elif n=='+':
		l+=1
print(l)