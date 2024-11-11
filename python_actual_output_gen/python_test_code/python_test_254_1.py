p,n,m=map(int,input().split())
if p==1:print(m==n)
elif n>m:print(0)
else:print((m-n)*(p-2)+1)
