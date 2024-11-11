# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n,k=map(int,input().split())
a=list(input())
i,j=0,0
while j<k and i<n:
	if i==0 and a[i]!='1' :
		a[i]='1'
		print('@')
		j+=1	
	elif i!=0 and a[i]!='0':
		a[i]='0'
		print('@')
		j+=1	
	i+=1
if n==1 and a[0]!='0' and k!=0:
	a[0]='0'
print(''.join(a))		