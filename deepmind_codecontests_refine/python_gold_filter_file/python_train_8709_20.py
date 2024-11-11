
n=int(input())
col={'purple':'Power','green':'Time','blue':'Space','orange':'Soul','red':'Reality','yellow':'Mind'}
l=0
for i in range(n):
	m=input()
	col.pop(m)
	l+=1
print(6-l)	
for key in col.keys():
	print(col[key])