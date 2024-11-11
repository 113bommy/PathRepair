n=int(input())
l=list(map(int,input().split()))
t=[]
z=[]
ans=0
for i in l:
	if i%2==0:
		t.append(i)
	else:
		z.append(i)
t.sort()
z.sort()
s=abs(len(t)-len(z))			
if s==0 or s==1:
	print(0)
elif len(z)>len(t)+1:
	print(sum(l[:s-1]))
else:
	print(sum(t[:s-1]))