def sieve(n):
	
	np=[0]*(n+1)
	for i in range(2,n+1):
		if np[i]==0:
			np[i]='1'
			for j in range(i*i,n+1,i):
				np[j]='2'
	return np
n=int(input())
t=sieve(n+1)
#print(t)
'''ans=[]
m=0
for i in range(1,n+1):
	if m<len(t) and i+1 ==t[m]:
		ans.append('1')
		m+=1
	else:
		ans.append('2')'''
if n==1 or n==2:
	print(1)
else:
	print(2)
print(' '.join(t[2:]))
