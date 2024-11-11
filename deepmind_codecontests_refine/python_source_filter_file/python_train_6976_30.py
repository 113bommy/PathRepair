import copy

n=int(input())
s=input().split(' ')
s1=[]
s2=[]
s1=copy.deepcopy(s)
s2=copy.deepcopy(s)

def Bubble_Sort(n,s1):
	m=0
	flag=1
	while flag:
		flag=0
		for i in range(1,n):
			j=n-i
			if int(s1[j][1])<int(s1[j-1][1]):
				a=s1[j]
				s1[j]=s1[j-1]
				s1[j-1]=a
				m+=1
				flag=1
	b=s1
	return(b)

def Selection_Sort(n,s2):
	m=0
	for i in range(n):
		minj=i
		for j in range(i,n):
			if int(s2[j][1])<int(s2[minj][1]):
				minj=j
		if i!=minj:
			a=s2[minj]
			s2[minj]=s2[i]
			s2[i]=a
			m+=1
	b=s2
	return(b)

s1=Bubble_Sort(n,s1)
s2=Selection_Sort(n,s2)

print(' '.join(s1))
print('stable')
print(' '.join(s2))
if s1==s2:
	print('Stable')
else:
	print('Not stable')
