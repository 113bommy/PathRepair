n,a,b,c= map(lambda x:int(x),input().split())
d = (4-(n%4))%4
if d==0: print(0)
elif d==1: print(min(a,3*c,c+b))
elif d==2: print(min(2*a,b,2*c))
else: print(min(3*a,c,a+b))