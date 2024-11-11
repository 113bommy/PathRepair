n=int(input())
l=list(map(int,input().split()))
l1=sorted(l)
m=int(input())
for i in range(n-1):
	l[i+1]=l[i+1]+l[i]
	l1[i+1]=l1[i+1]+l1[i]
l1=[0]+l1
l=[0]+l
for i in range(m):
	r1=list(map(int,input().split()))
	if r1[0]==1:
		print(l[r1[2]]-l[r1[1]-1])
	else:
		print(l1[r1[2]]-l1[r1[1]-1])
		
