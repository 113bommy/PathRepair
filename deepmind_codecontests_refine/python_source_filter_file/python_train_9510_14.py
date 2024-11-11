n=int(input())

l=list(map(int,input().split()))
d={}
m=min(l)
for i in l:
	d[i]=0

for i in l:
	d[i]+=1

if d[m]>1:
	print("Still Rozdill")
else:
	print(l.index(m)+1)
