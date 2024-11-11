n=int(input())
a=[input() for i in range(n)]
b=['purple','green','orange','red','yellow','blue']
d={'purple':'Power','blue':'Space','green':'Time','orange':'Soul','red':'reality','yellow':'Mind'}
for i in range(len(a)):
	b.remove(a[i])
print(len(b))	
for i in range(len(b)):
	print(d[b[i]])