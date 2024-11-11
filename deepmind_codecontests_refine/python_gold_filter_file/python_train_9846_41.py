b=0
n=int(input())
l=list(map(int,input().split()))
for i in range(n):
	if l[i]!=max(l):
		b+=max(l)-l[i]
		continue
	elif len(l)==1:
		print('0')
		break
else:
	print(b)
