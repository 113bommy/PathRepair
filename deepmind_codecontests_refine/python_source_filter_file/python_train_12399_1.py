n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
s1,s2=0,0
turn=0
for i in range(2*n-1):
	if turn==0:
		if len(a)>0 and len(b)>0:	
			if a[-1]>b[-1]:
				s1+=a[-1]
				a.pop()
			else:
				b.pop()
		elif len(a)>0:
			s1+=a[-1]
			a.pop()
		else:
			b.pop()
		turn=1
	else:
		if len(a)>0 and len(b)>0:
			if b[-1]>a[-1]:
				s2+=b[-1]
				b.pop()
			else:
				a.pop()
		elif len(a)>0:
			a.pop()
		else:
			s2+=b[-1]
			b.pop()
		turn = 0
	#print(a,b)

print(s1-s2)
