
n=int(input())
col={'purple':'power','green':'time','blue':'space','orange':'soul','red':'reality','yellow':'mind'}
l=0
for i in range(n):
	m=input()
	col.pop(m)
	l+=1
print(6-l)	
for key in col.keys():
	print(col[key])