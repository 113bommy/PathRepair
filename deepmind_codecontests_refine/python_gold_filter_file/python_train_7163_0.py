n,a,b=map(int,input().split())
and_=min(a,b)
or_=max(0, a+b-n)
print(and_, or_)