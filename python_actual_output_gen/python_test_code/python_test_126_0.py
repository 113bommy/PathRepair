R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:
 n,k=R();l,*a=R();h=l;f=0
 for x in a:l=max(l-k+1,x);h=min(h,x)+k-1;f|=l>h
 print('YNEOS'[f|(a[-1]>l)::2])