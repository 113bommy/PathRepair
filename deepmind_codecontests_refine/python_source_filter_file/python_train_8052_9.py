d ={1:6,
	2:5,
	3:4,
	4:3,
	5:2,
	6:1}
n=int(input())
x=int(input())
a=[]
b=[]
res='YES'
for i in range(n):
	s=map(int,input().split())
	if d[x] in s:
		res='NO'
	elif x in s:
		res='NO'
print(res)