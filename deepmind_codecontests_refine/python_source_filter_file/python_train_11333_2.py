W,H=map(int,input().split())
p=sorted(int(input())for _ in'_'*W)
p+=10**18,
q=sorted(int(input())for _ in'_'*H)
q+=10**18,
z=i=j=0
h,w=H+1,W+1
while i<W or j<H:
	if h*p[i]<w*q[j]:
		z+=h*p[i]
		i+=1
		w-=1
	else:
		z+=w*q[j]
		j+=1
		h-=1
print(z)
