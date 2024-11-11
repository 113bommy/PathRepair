A=10**15;n=int(input());c=[];o=[0]*3
for i in range(3):
	a,b=map(int,input().split())
	n=n-a;c.append(b-a);o[i]=a
o[0]=o[0]+min(c[0],n);n=n-min(c[0],n)
o[2]=o[2]+min(c[2],n);n=n-min(c[2],n)
o[1]=o[1]+min(c[1],n);n=n-min(c[1],n)
print(o[0],o[1],o[2])