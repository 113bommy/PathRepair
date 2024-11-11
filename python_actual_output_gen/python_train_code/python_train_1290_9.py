I=lambda:list(map(int,input().split()))[::-1];m,n=I();l=[I()+[i]for i in range(m)];c=[0]*-~n;a=[0]*m
for y,p,i in sorted(l):c[p]+=1;a[i]='%06d'%p+'%06d'%c[p]
print('\n'.join(t))