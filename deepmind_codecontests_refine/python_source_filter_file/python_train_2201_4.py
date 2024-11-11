a1,b1=map(int,input().split(':'))
a2,b2=map(int,input().split(':'))
c=((a2-a1)*60+(b2-b1))//2
a1+=c//60
b1+=c%60
if b1>60:
	b1-=60
	a1+=1
print('{}:{:02d}'.format(a1,b1))
