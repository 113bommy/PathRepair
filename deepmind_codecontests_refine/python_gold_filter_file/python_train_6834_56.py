n=int(input())
li=[]
while n>1:
	li.append('8')
	n-=2
	if len(li)>18:
		print("-1")
		exit()
if n==1:
	li.append('6')
	if len(li)>18:
		print("-1")
		exit()
print(''.join(li))
