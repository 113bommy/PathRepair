a,b,c=map(int,input().split())
if c==0:print(['NO','YES'][a==b])
else:print(['NO','YES'][(b-a)//c>0and(b-a)%c==0])