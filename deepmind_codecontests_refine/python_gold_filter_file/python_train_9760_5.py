# Meet

n = int(input())
a=[]
for i in range(n):
	temp = [int(x) for x in input().split()]
	a+=[temp]

m = int(input())
b=[]
for i in range(m):
	temp = [int(x) for x in input().split()]
	b+=[temp]

s=0
a.sort()
b.sort()

i=0
j=0
while i<n and j<m:
	if a[i][0]==b[j][0]:
		s+=max(a[i][1], b[j][1])
		i+=1
		j+=1
	elif a[i][0]<b[j][0]:
		s+=a[i][1]
		i+=1
	elif a[i][0]>b[j][0]:
		s+=b[j][1]
		j+=1

while i<n:
	s+=a[i][1]
	i+=1

while j<m:
	s+=b[j][1]
	j+=1

print(s)