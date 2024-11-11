from math import *
n,k=[int(i) for i in input().split()]
b=bin(n)[2:]
o=b.count('1')

if o>k or k>n:
	print('NO')
	quit()

print('YES')
k-=o
#print(b)
ans=[]
for i in range(len(b)-1,-1,-1):
	#print(ans)
	if b[i]=='1':
		t=int(pow(2,len(b)-1-i))
		#ans.append(pow(2,b))
		#print(t,k)
		if k>=t-1:
			ans+=[1]*t
			k-=(t-1)
		else:
			l=ceil(len(b)-1-i-log(k+1,2))
			#print(l)
			#l=int((k-1)/2)
			#at=[t/pow(2,l)]*pow(2,l)
			k-=(pow(2,len(b)-i-1-l)-1)
			#print(k)
			#print(l,t)
			ans+=[pow(2,l)]*int(pow(2,len(b)-i-1-l)-k)+[pow(2,l-1)]*int(2*k)
	#print(ans)
ans.sort()
for i in ans:
	print(int(i),end=' ')