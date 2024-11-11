I=lambda:list(map(int,input().split()));n,m=I();l=[I()+[i]for i in range(M)];c=[0]*-~N;a=[0]*M
for p,y,i in sorted(l,key=lambda x:x[1]):c[p]+=1;a[i]='%06d'%p+'%06d'%c[p]
for t in a:print(t)