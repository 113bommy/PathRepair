n,q=map(int,input().split())
s=[0]*-~n
w=m=0
for _ in[0]*q:
 a,v=map(int,input().split())
 s[a]+=v
 if v<0 and a==w:m=max(s);w=s.index(m)
 elif s[a]>maxv:w,m=a,s[a]
 elif s[a]==maxv:w=min(w,a)
 print(w,m)
