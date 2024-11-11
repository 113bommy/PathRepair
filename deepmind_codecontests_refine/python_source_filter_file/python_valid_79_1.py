"""input
7
3
237
5
44444
3
221
2
35
3
773
1
4
30
626221626221626221626221626221


"""
def notprime(n):
	for i in range(2,int(n**0.5)+1):
		if(n%i==0):
			return True
	return False
for tt in range(int(input())):
	x=int(input())
	l=list(input())
	z=list(dict.fromkeys(l))
	a=0
	for i in z:
		if(i in '14689'):
			print(1)
			print(i)
			a=1
			break
	if(a==1):
		continue
	l=l[:3]
	y=[int(l[i]+l[j]) for i in range(len(l)) for j in range(len(l)) if(j!=i)]
	for i in y:
		if(notprime(i)):
			print(2)
			print(i)
			break

