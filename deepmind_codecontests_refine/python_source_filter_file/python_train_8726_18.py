h,w,d,*l=map(int,open(0).read().split())
s=h*w+1;x=[0]*s;y=[0]*s;k=[0]*s
for i,a in enumerate(l[:s]):x[a]=i//w;y[a]=i%w
for i in range(d+1,s-1):k[i]=k[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d])
for l,r in zip(l[s::2],l[s+1::2]):print(k[r]-k[l])