n,a,b,c,d=map(int,input().split())
q=1
w=-(b+d-a-b)+q
e=-(c+d-a-b)+q
r=-(c+a-a-b)+q
x=n-max(q,w,e,r)+1
y=1-min(q,w,e,r)
print((x-y)*n)