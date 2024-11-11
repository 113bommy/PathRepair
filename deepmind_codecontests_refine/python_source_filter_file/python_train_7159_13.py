def A(i,x):
 while~i>~n:t[i]+=x;i+=i&-i
(n,q),c,*z=[[*map(int,t.split())]for t in open(0)]
a=[0]*q
j,*b=t=[0]*(n+2)
for i,(l,r)in sorted(zip(range(q),z),key=lambda x:x[1][1]):
 while j<r:d=c[j];j+=1;A(b[d]+1,1);b[d]=j;A(j+1,-1)
 while l:a[i]+=t[l];l-=l&-l
print(*a)