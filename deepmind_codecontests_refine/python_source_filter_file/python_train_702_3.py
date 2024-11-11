n,*a=map(int,open(0).read().split())
s,*l=[0]*100001
for i in a[:n]: s+=i; l[i]+=1
for b,c in zip(*[iter(a[n+1:])]*2): s+=(c-b)*l[b]; l[c]+=l[b]; l[b]=0; print(s)