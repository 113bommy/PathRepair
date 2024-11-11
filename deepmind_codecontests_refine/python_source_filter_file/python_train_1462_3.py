r,s=map(int,input().split())
a=d=1,b=c=0
while r:q=r//s;r,s,a,c,b,d=s,r%s,c,a-q*c,d,b-q*d
print(a,b)
