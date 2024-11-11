n=int(input())
c=p=0
while(n%7!=0 and n>=4):
	n=n-4
	p+=1
if(n%7==0):
	print(p*'4'+(n//7)*'7')
else:
	print(-1)

	